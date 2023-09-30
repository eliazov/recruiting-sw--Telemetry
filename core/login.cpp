#include "login.h"
#include <iostream>

struct user_login{
    char u_name[64];
    char u_pasw[64];
    utente status;
};

user_login user_reg[]={{"Paolo", "password", admin},{"Pietro", "12345", log}};
char username[64] = "";
char password[64] = "";

void login(utente &u_current){

    if (u_current==noLog) {
        ImGui::InputText("Username", username, sizeof(username));
        ImGui::InputText("Password", password, sizeof(password), ImGuiInputTextFlags_Password);
        if (ImGui::Button("Login")) {
            // Qui dovresti aggiungere la logica per verificare il login
            for(user_login x : user_reg){
                if (strcmp(username, x.u_name) == 0 && strcmp(password, x.u_pasw) == 0) {
                    u_current = x.status;
                }
            }
            strcpy(username, "");
            strcpy(password, "");
        }
        ImGui::End();  
    }
    else{
        ImGui::Text("User logged-in");
        if(ImGui::Button("log out")){
           u_current=noLog;
        }
    }       
}