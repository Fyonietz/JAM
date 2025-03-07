#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <Windows.h>

int main()
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);

    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_HIDE);
    std::time_t current_time = std::time(__nullptr);

    std::tm* localtime = std::localtime(&current_time);
;
    sf::RenderWindow window(sf::VideoMode(300, 200), "Ini Jam");
    HWND hwnd = window.getSystemHandle();
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    sf::Font font;
    font.loadFromFile("pixel.ttf");

    sf::Text timeText;
    timeText.setFont(font);
    timeText.setCharacterSize(40);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(27,67);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::time_t currentTime = std::time(nullptr);
        std::tm localTime;
        if (localtime_s(&localTime, &currentTime) == 0) {
            char timeStr[9];
            std::sprintf(timeStr, "%02d:%02d:%02d", localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
            timeText.setString(timeStr);
        }
        window.clear();
        window.draw(timeText);
        window.display();
    }

    return 0;
}