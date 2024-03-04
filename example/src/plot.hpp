#include <raylib.h>
#include <iostream>


class plot
{
private:

    // Zmienne Prywatne

    int *points;
    int r_min;
    int r_max;
    const char *r_title;
    bool show_points;
    Color Line_color;
    Color Point_color;
    int PPS;
    int s_height; 
    int s_width;
    int index_seconds = 0;
    int points_number;

public:

    // Konstruktor
    plot(int _points[], int _points_number, int _r_min, int _r_max, const char *_r_title, Color _Line_color, bool _show_points, Color _Point_color, int _PPS, int _s_height, int _s_width) {

        // Ustawianie Zmiennych

        points = _points;
        r_min = _r_min;
        r_max = _r_max;
        r_title = _r_title;
        Line_color = _Line_color;
        show_points = _show_points;
        Point_color = _Point_color;
        PPS = _PPS;
        s_height = _s_height;
        s_width = _s_width;
        points_number = _points_number;
    }

    // Następne Sekundy
    void sec_update(int second) {index_seconds+=second;}

    void info() {
        std::cout << "Plot Information:\n";
        std::cout << "Range: " << r_min << " - " << r_max << "\n";
        std::cout << "Title: " << r_title << "\n";
        std::cout << "Show Points: " << show_points << "\n";
        std::cout << "Points Per Second: " << PPS << "\n";
    }
    void show() {

        DrawText(r_title, 10, 10, 2, BLACK);

        // Down Up
        for (int i = r_min; i <= r_max; ++i) {
            int y = s_height - 50 - (i - r_min) * (s_height - 100) / (r_max - r_min);
            DrawText(std::to_string(i).c_str(), 20, y, 10, BLACK);
        }

        DrawLine(40, 575, 40, 25, BLACK);

            // Left Right
        for (int i = 0; i <= 10; ++i) {
            int x = 50 + i * (s_width- 100) / 10;
            DrawText(std::to_string(index_seconds + i).c_str(), x, s_height - 20, 10, BLACK);
        }

        DrawLine(40, 574, 775, 574, BLACK);


        int gap = 50/PPS;

        for (int i = 0; i < points_number; ++i) {
            int x = 75 + i * gap; 
            int y = s_height - 50 - (points[i] - r_min) * (s_height - 100) / (r_max - r_min); 
            
            if (show_points==true) {
                DrawCircle(x, y, 7, Point_color);
            }
            
            if (i > 0) {
                int prevX = 75 + (i - 1) * gap;
                int prevY = s_height - 50 - (points[i - 1] - r_min) * (s_height - 100) / (r_max - r_min);
                DrawLine(prevX, prevY, x, y, Line_color); // Lines
            }
        }

    }

    void change_plot(int *pts, int pts_number) {

        points = pts;
        points_number = pts_number;

    }

};
