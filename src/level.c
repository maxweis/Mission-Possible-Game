#include "level.h"

char *object_list[] = {
        "art/sprites/object/glass_64.png",
        "art/sprites/object/glass_32.png",
        "art/sprites/object/foliage_64.png",
        "art/sprites/object/foliage_32.png",
        "art/sprites/object/roof_64.png",
        "art/sprites/object/roof_32.png",
        NULL
};

char *background_list[] = {
        "art/backgrounds/brick.jpg",
        "art/backgrounds/grass.png"
};

void AddLevelObject()
{
        for (int n = 0; object_values[n][0] != -1; n++)
                AddObject(*CreateObject(object_values[n][0],
                                        object_values[n][1], object_values[n][2], 
                                        IDK, IDK, object_values[n][3], object_values[n][4],
                                        (int) object_values[n][5]));
}

void LoadLevel(char *level_name)
{
        for (int i = 0; i < OBJECT_LIMIT; i++)
                for (int n = 0; n < VALUES_NUMBER; n++)
                        object_values[i][n] = -1;

        FILE *file = fopen(level_name, "r");
        int x = 0;
        int n = 0;
        
        if (file == NULL)
                fprintf(stderr, "Could not open %s", level_name);
        else{
                fscanf(file, "%d", &level_background);
                while (!feof(file)){
                        for (int i = 0; i < VALUES_NUMBER; i++)
                                fscanf(file, "%d", &object_values[n][i]);
                        n++;
                }
        }
        AddLevelObject();
}
