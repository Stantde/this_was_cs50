#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int max_lights = 4;
    char light[max_lights] = {'1', '2', '3', '4'};
    int time[max_lights] = {939, 939, 848, 0};

    for (int i = 0; i < max_lights; i++)
    {
        printf("light %c, time %i\n", light[i], time[i]);
    }
}
