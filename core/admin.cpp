#include "admin.h"
#include <iostream>

void sl_admin(bool &sc1, bool &sc2){
    ImGui::Text("Choose the schedule you want to see: ");
        ImGui::Checkbox("lapTime", &sc1);
        ImGui::Checkbox("temperature", &sc2);
        
}