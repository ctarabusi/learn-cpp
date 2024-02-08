#include "raycast.h"

constexpr int NUMBER_OF_RAYS = 200;
constexpr int HALF_NUMBER_OF_RAYS = NUMBER_OF_RAYS / 2;
constexpr int MAX_DEPTH = 10;

void Raycast::rayCastPlayer(bool debug_mode, sf::RenderWindow& window, Player& player, World& world, sf::Texture& texture) {
    GridCell grid_cell = world.getGridPosition(player.positionX, player.positionY);

    int rayIndex = 0;
    for (int i = 0; i < NUMBER_OF_RAYS; i++) {

        auto angleRaycast = player.angle + (i - HALF_NUMBER_OF_RAYS) * 0.005f + 0.0001;

        float sinAngle = sin(angleRaycast);
        float cosAngle = cos(angleRaycast);

        int x_map = grid_cell.x * world.GRID_X_SIZE;
        int y_map = grid_cell.y * world.GRID_Y_SIZE;

        // horizontals
        float y_horizontal;
        int dy;
        if (sinAngle > 0) {
            y_horizontal = y_map + world.GRID_Y_SIZE;
            dy = world.GRID_Y_SIZE;
        }
        else {
            y_horizontal = y_map - 1;
            dy = -(world.GRID_Y_SIZE);
        }

        float depth_hor = (y_horizontal - player.positionY) / sinAngle;
        float x_horizontal = player.positionX + depth_hor * cosAngle;

        float deltaDepthHor = dy / sinAngle;
        float dx = deltaDepthHor * cosAngle;

        int depth = 1;
        while (depth < MAX_DEPTH) {

            auto positionCell = world.getGridPosition(x_horizontal, y_horizontal);

            if (world.checkWall(positionCell.x * world.GRID_X_SIZE, positionCell.y * world.GRID_Y_SIZE)) {
                x_horizontal += dx;
                y_horizontal += dy;
                depth_hor += deltaDepthHor;
                depth++;
            }
            else {
                break;
            }
        }

        // verticals
        float x_vertical;
        float y_vertical;

        if (cosAngle > 0) {
            x_vertical = x_map + world.GRID_X_SIZE;
            dx = world.GRID_X_SIZE;
        }
        else {
            x_vertical = x_map - 1;
            dx = -(world.GRID_X_SIZE);
        }

        float depth_vert = (x_vertical - player.positionX) / cosAngle;
        y_vertical = player.positionY + depth_vert * sinAngle;

        float delta_depth = dx / cosAngle;
        dy = delta_depth * sinAngle;

        depth = 1;
        while (depth < MAX_DEPTH) {

            auto positionCell = world.getGridPosition(x_vertical, y_vertical);

            if (world.checkWall(positionCell.x * world.GRID_X_SIZE, positionCell.y * world.GRID_Y_SIZE)) {
                x_vertical += dx;
                y_vertical += dy;
                depth_vert += delta_depth;
                depth++;
            }
            else {
                break;
            }
        }


        float depthValue = 0.f;
        if (depth_vert < depth_hor) {
            depthValue = depth_vert;
        }
        else {
            depthValue = depth_hor;
        }

        std::unique_ptr<sf::VertexArray> line = std::make_unique<sf::VertexArray>(sf::Lines, 2);

        int scale = world.width / NUMBER_OF_RAYS;

        float depthWithoutFishEye = depthValue * cos(player.angle - angleRaycast);

        if (debug_mode) {
            int finalX = player.positionX + depthValue * cosAngle;
            int finalY = player.positionY + depthValue * sinAngle;
            (*line)[0].position = sf::Vector2f(player.positionX, player.positionY);
            (*line)[0].color = sf::Color::Blue;
            (*line)[1].color = sf::Color::Blue;
            (*line)[1].position = sf::Vector2f(finalX, finalY);

            window.draw(*line);
        }
        else {
            sf::RectangleShape obstacle(sf::Vector2f(scale, 20000.f / depthWithoutFishEye));
            obstacle.setPosition(rayIndex * scale, world.heigth / 2 - (20000.f / depthWithoutFishEye) / 2);

            obstacle.setTexture(&texture); // Set the texture
            obstacle.setTextureRect(sf::IntRect(rayIndex * scale, 0, scale, 1000)); // Set the texture rectangle to cover the whole texture

            window.draw(obstacle);
        }

        rayIndex++;

    }

}
