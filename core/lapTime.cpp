#include "lapTime.h"
#include <iostream>
float n=0;
float data[] = { 3, 4, 8, 1, 7, 4, 9};

void LapTime(){
    ImGui::InputFloat("", &n);
        if (ImGui::Button("go")){
            for(int i=0; i<6; i++){
                data[i]=data[i+1];
            }
            data[6]=n;
        }
    int data_count = sizeof(data) / sizeof(float);
    ImGui::PlotLines("", data, data_count, 0, "Lap Time", FLT_MAX, FLT_MAX, ImVec2(800, 400));
}