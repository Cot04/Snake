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
    int frame = 60;
    int frame1 = 70;
    int frame2 = 80;
    int frame3 = 90;
    auto can = Canvas(200,200);
    can.DrawPointCircle(47,53,20);

    can.DrawPointCircle(40,50,5);
    can.DrawPointCircle(40,50,1);

    can.DrawPointCircle(53,50,5);
    can.DrawPointCircle(53,50,1);

    can.DrawPointLine(40,65,55,65);

    can.DrawPointLine(37,73,27,80);
    can.DrawPointLine(57,73,67,80);

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

        can.DrawPointLine(frame,30,60,20);
        can.DrawPointLine(frame,30,60,20);
        can.DrawPointLine(frame,30,60,20);
        can.DrawPointLine(frame,30,60,20);
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        //        Element personaje = spinner(21, frame);
        Element lienzo = bgcolor(Color::Blue,canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}