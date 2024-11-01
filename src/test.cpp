#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 160;
    int frame1 = 180;
    int frame2 = 160;
    int frame3 = 180;
    int frame4 = 140;
/*    auto ColorSupport = vbox({
                            Terminal::ColorSupport() >= Terminal::Color::Palette16
                                ? text(" 16 color palette support : Yes")
                                : text(" 16 color palette support : No"),
                            Terminal::ColorSupport() >= Terminal::Color::Palette256
                                ? text("256 color palette support : Yes")
                                : text("256 color palette support : No"),
                            Terminal::ColorSupport() >= Terminal::Color::TrueColor
                                ? text("       True color support : Yes")
                                : text("       True color support : No"),
                        }); */
    while (true)
    {
        auto can = Canvas(400,200);
        can.DrawPointCircle(47,53,20); // Cara

        can.DrawPointCircle(40,50,5); // Ojo 
        can.DrawPointCircle(40,50,1);

        can.DrawPointCircle(53,50,5); // Ojo
        can.DrawPointCircle(53,50,1);

        can.DrawPointLine(40,65,55,65); // Boca

        can.DrawPointLine(37,73,27,80); // Cuello
        can.DrawPointLine(57,73,67,80); // Cuello
        
        can.DrawPointLine(frame,50,frame1,50); // Parte alta ladrillo
        can.DrawPointLine(frame,60,frame1,60); // Parte baja ladrillo
//        can.DrawPointLine(frame2,60,frame2,50); // Izquierda ladrillo
        can.DrawPointLine(frame3,60,frame3,50); // Derecha ladrillo
        can.DrawPointLine(frame4,55,frame,50); // Punta
        can.DrawPointLine(frame4,55,frame,60); // Punta
//        can.DrawText(frame,55, std::string Santi); 
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        //        Element personaje = spinner(21, frame);
        Element lienzo = bgcolor(Color::Blue,canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.05s);
        if (frame4 > 67){
            frame--;
            frame1--;
            frame2--;
            frame3--;
            frame4--;
        }
        else{
            frame = frame;
            frame1 = frame1;
            frame2 = frame2;
            frame3 = frame3;
            frame4 = frame4;
        }
    }

    return 0;
}