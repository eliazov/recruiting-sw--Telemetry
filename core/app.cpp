#include "app.h"
#include "login.h"
#include "lapTime.h"
#include <iostream>
#include <string>
#include <vector>
#include "tempRuote.h"

utente u_current=noLog;
char status[]="you are not able to see this tab. Try to log-in if you didn't do it before";
void app_render(){

/*
Se l'utente non è loggato mostra solo la schermata iniziale.
Se è loggato come user normale mostra anche la scheda con il grafico dei tempi sul giro
Se l'utente loggato è admin può accedere anche alla scheda che mostra le temperaature delle gomme
*/

    if (ImGui::BeginTabBar("TabBar")){
        if (ImGui::BeginTabItem("Home")){
                
            ImGui::Text("This page is visible to everybody.");
            ImGui::Text("The visibility of the other pages depend on the status of the user: it can be");
            ImGui::Text("Admin - Logged - No-Logged");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("LapTime")){
            if(u_current!=noLog){
                LapTime();
            }
            else{
                ImGui::Text(status);
            }
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Temperature")){
            if(u_current==admin){
                temp_ruote();
            }
            else{
                ImGui::Text(status);
            }
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("login")){
            // Contenuto della Scheda 2
            ImGui::Text("Login");
            login(u_current);
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    
   


}