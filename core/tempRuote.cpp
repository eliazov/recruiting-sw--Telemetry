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
    ImU32 color=IM_COL32(0, 255, 0, 255);
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    float y2=120;
    float x2=10;
    for(int i=0; i<4; i++){
        float x=wheel[i].position.x+length;
        float y=wheel[i].position.y;
        if(wheel[i].temp > 90.0f){
            color=IM_COL32(255, 0, 0, 255);
        }
        drawList->AddLine(wheel[i].position, ImVec2(x, y), color, thickness);
        color=IM_COL32(0, 255, 0, 255);
        if(i==2){
            x2=280;
            y2=120;
        }
        ImGui::SetCursorPos(ImVec2(x2, y2));
        ImGui::Text("%.1f °C", wheel[i].temp);
        y2 += 200;
    }

}
float n1=70.0f, n2=70.0f, n3=70.0f, n4=70.0f;
void temp_ruote(){

        
        ImVec2 WheelStart = ImGui::GetCursorScreenPos();
        float x=WheelStart.x+80;
        float y=WheelStart.y+50;
        wheel[0]={ImVec2(x, y), n1};
        wheel[1]={ImVec2(x, y+200), n2};
        wheel[2]={ImVec2(x+140, y), n3};
        wheel[3]={ImVec2(x+140, y+200), n4};
        
        DrawCarWheel();
        ImGui::Text("Temperature of the wheels: ");
        ImGui::InputFloat("g1", &n1);
        ImGui::InputFloat("g2", &n2);
        ImGui::InputFloat("g3", &n3);
        ImGui::InputFloat("g4", &n4);

}
