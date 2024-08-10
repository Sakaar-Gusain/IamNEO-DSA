#include <iostream>
#include <thread>
#include <chrono>

class TrafficLight {
public:
    enum LightState { RED, GREEN, YELLOW };

    TrafficLight() : state(RED) {}

    void changeLight() {
        switch (state) {
            case RED:
                state = GREEN;
                break;
            case GREEN:
                state = YELLOW;
                break;
            case YELLOW:
                state = RED;
                break;
        }
    }

    void displayLight(int duration) const {
        switch (state) {
            case RED:
                std::cout << "RED light" << std::endl;
                countdown(duration);
                break;
            case GREEN:
                std::cout << "GREEN light" << std::endl;
                countdown(duration);
                break;
            case YELLOW:
                std::cout << "YELLOW light" << std::endl;
                countdown(duration);
                break;
        }
    }

    void run(int cycles) {
        for (int i = 0; i < cycles; ++i) {
            switch (state) {
                case RED:
                    displayLight(10);
                    break;
                case GREEN:
                    displayLight(5);
                    break;
                case YELLOW:
                    displayLight(3);
                    break;
            }
            changeLight();
        }
    }

private:
    LightState state;

    void countdown(int duration) const {
        for (int i = duration; i > 0; --i) {
            std::cout << i << " seconds remaining" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

int main() {
    TrafficLight light;
    int cycles;
    std::cout << "Enter the number of cycles: ";
    std::cin >> cycles;
    light.run(cycles);
    return 0;
}
