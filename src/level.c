#include "level.h"

char *object_list[] = {
        "art/sprites/object/glass.png",
        "art/sprites/main/base.png"
};

void AddLevelObject()
{
        for (int n = 0; object_values[n][0] != -1; n++)
                AddObject(*CreateObject(object_values[n][0],
                                        object_values[n][1], object_values[n][2], 
                                        IDK, IDK, object_values[n][3], object_list[object_values[n][4]]));
}

void LoadLevel(char *level_name)
{

        for (int i = 0; i < OBJECT_LIMIT; i++)
                for (int n = 0; n < 5; n++)
                        object_values[i][n] = -1;

        FILE *file = fopen(level_name, "r");
        int x = 0;
        int n = 0;
        
        if (file == NULL)
                fprintf(stderr, "Could not open %s", level_name);
        else{
                while (!feof(file)){
                        for (int i = 0; i < 5; i++)
                                fscanf(file, "%d", &object_values[n][i]);
                        n++;
                }
        }
        AddLevelObject();
}
