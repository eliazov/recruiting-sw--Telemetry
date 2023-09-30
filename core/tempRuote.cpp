#include "tempRuote.h"
#include <iostream>

struct tempWheels
{
    ImVec2 position;
    float temp;
};

tempWheels wheel[4];
void DrawCarWheel() {
    float length=40.0f;
    float thickness=50.0f;
    ImU32 color=IM_COL32(255, 0, 0, 255);
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    float y2=120;
    float x2=10;
    for(int i=0; i<4; i++){
        float x=wheel[i].position.x+length;
        float y=wheel[i].position.y;
        drawList->AddLine(wheel[i].position, ImVec2(x, y), color, thickness);
        if(i==2){
            x2=280;
            y2=120;
        }
        ImGui::SetCursorPos(ImVec2(x2, y2));
        ImGui::Text("%.1f °C", wheel[i].temp);
        y2 += 200;
    }

}

void temp_ruote(){

        ImGui::Text("Temperature of the wheels: ");

        ImVec2 WheelStart = ImGui::GetCursorScreenPos();
        float x=WheelStart.x+80;
        float y=WheelStart.y+50;
        wheel[0]={ImVec2(x, y), 18.0f};
        wheel[1]={ImVec2(x, y+200), 40.0f};
        wheel[2]={ImVec2(x+140, y), 2.0f};
        wheel[3]={ImVec2(x+140, y+200), 300.0f};
        
        DrawCarWheel();

}