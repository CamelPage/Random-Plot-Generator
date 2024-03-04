# Code Structure
The code is composed of two parts:

- The main function, which initializes the window, creates a plot object, and runs the main loop.
- The plot class, which contains the methods and variables needed to create and update the plot.
main Function

The main function initializes the window, creates a plot object, and runs the main loop. 

The plot object is created with an array of points, the minimum and maximum range of the plot, the plot title, the line and point colors, the number of points per second, and the window size.

Inside the main loop, the program clears the screen, draws the plot, and updates the points array with random numbers. If the number of points exceeds the maximum number of points per second, the program clears the plot and resets the points array.

# plot Class
The plot class contains the following methods and variables:

``` plot(int _points[], int _points_number, int _r_min, int _r_max, const char *_r_title, Color _Line_color, bool _show_points, Color _Point_color, int _PPS, int _s_height, int _s_width) ```
- The constructor initializes the plot object with the given parameters.
``` void sec_update(int second) ``` 
- Increases the index of seconds by the given amount.
```void info()``` 
- Prints the plot information to the console.
```void show()``` 
- Draws the plot to the screen.
```void change_plot(int *pts, int pts_number)``` 
- Changes the points array and the number of points.
The show method draws the plot title, the x and y axes, the points, and the lines connecting the points. The change_plot method updates the points array and the number of points.



# With Points

Code: ```plot test_plot(plt, 1, -10, 10, "Jakis Plot", BLUE, true, BLUE, PPS, 600, 800);```

![Logo](https://i.postimg.cc/DzsmxG17/Zrzut-ekranu-2024-03-04-202532.png) 

# Without Points
Code: ```plot test_plot(plt, 1, -10, 10, "Jakis Plot", BLUE, false, BLUE, PPS, 600, 800);```

![Logo](https://i.postimg.cc/Kz2jwY5B/Zrzut-ekranu-2024-03-04-202505.png)

