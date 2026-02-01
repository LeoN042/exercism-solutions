#include "robot_simulator.h"
#include <stddef.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_status_t robot;
    robot_position_t pos;
    pos.x = x;
    pos.y = y;
    robot.direction = direction;
    robot.position = pos;
    return robot;
}
void robot_move(robot_status_t *robot, const char *commands) {
    if (commands == NULL) {
        return;
    }
    for (int i = 0; commands[i] != '\0'; i++) {
        switch (commands[i]) {
            case 'R':
                robot->direction = (robot->direction + 1) & 3;
                break;
            case 'L':
                robot->direction = (robot->direction - 1) & 3;
                break;
            case 'A':
                if (robot->direction == DIRECTION_NORTH) {
                    robot->position.y += 1;
                }
                else if (robot->direction == DIRECTION_EAST) {
                    robot->position.x += 1;
                }
                else if (robot->direction == DIRECTION_SOUTH) {
                    robot->position.y -= 1;
                }
                else if (robot->direction == DIRECTION_WEST) {
                    robot->position.x -= 1;
                }
                break;
            default:
                break;
        }
    }
}