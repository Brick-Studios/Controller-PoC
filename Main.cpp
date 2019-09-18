#include <SDL.h>
#include <iostream>

SDL_Joystick *joy;

// Initialize the joystick subsystem

int main() {

    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    // Check for joystick
    if (SDL_NumJoysticks() > 0) {
        // Open joystick
        joy = SDL_JoystickOpen(0);
    
        if (joy) {
            std::cout << "Opened Joystick 0" << std::endl;
            std::cout << "Name: " << SDL_JoystickNameForIndex(0) << std::endl;
            std::cout << "Number of Axes: " << SDL_JoystickNumAxes(joy) << std::endl;
            std::cout << "Number of Buttons: " << SDL_JoystickNumButtons(joy) << std::endl;
            std::cout << "Number of Balls: " << SDL_JoystickNumBalls(joy) << std::endl;
        } else {
            std::cout << "Couldn't open Joystick 0" << std::endl;
        }

        SDL_Event e;

        //Print all events
        while(true)
        {
            while( SDL_PollEvent( &e ) != 0 )
            {
                std::cout << "Someone pressed a button!" << std::endl;
                std::cout << e.type << std::endl;
            }
        }
    
        // Close if opened
        if (SDL_JoystickGetAttached(joy)) {
            SDL_JoystickClose(joy);
        }
    } else {
        std::cout << "Controller not connected" << std::endl;
    }
}

