#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Point.h"
#include "Window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Oasis : Graph_lib::Window
{
    Oasis(Point xy, int w, int h, const string& title);

private:
  //Declaring all items. Rectangle and Button pairs and their boolean vals
  Rectangle r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16;
  Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15;
  bool boo1=false;bool boo2=false;bool boo3=false;bool boo4=false;
  bool boo5=false;bool boo6=false;bool boo7=false;bool boo8=false;
  bool boo9=false;bool boo10=false;bool boo11=false;bool boo12=false;
  bool boo13=false;bool boo14=false;bool boo15=false;

  //Declaring the callbacks
  static void cb_b1(Address, Address);
  static void cb_b2(Address, Address);
  static void cb_b3(Address, Address);
  static void cb_b4(Address, Address);
  static void cb_b5(Address, Address);
  static void cb_b6(Address, Address);
  static void cb_b7(Address, Address);
  static void cb_b8(Address, Address);
  static void cb_b9(Address, Address);
  static void cb_b10(Address, Address);
  static void cb_b11(Address, Address);
  static void cb_b12(Address, Address);
  static void cb_b13(Address, Address);
  static void cb_b14(Address, Address);
  static void cb_b15(Address, Address);

  //Declaring the functions
  void f1();void f2();void f3();void f4();void f5();void f6();void f7();
  void f8();void f9();void f10();void f11();void f12();void f13();void f14();
  void f15();
};

//------------------------------------------------------------------------------

Oasis::Oasis(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title), //making the window
    b1(Point(50,50),100,100,"btn1",cb_b1),  //These are the button creations
    b2(Point(150,50),100,100,"btn2",cb_b2),
    b3(Point(250,50),100,100,"btn3",cb_b3),
    b4(Point(350,50),100,100,"btn4",cb_b4),
    b5(Point(50,150),100,100,"btn5",cb_b5),
    b6(Point(150,150),100,100,"btn6",cb_b6),
    b7(Point(250,150),100,100,"btn7",cb_b7),
    b8(Point(350,150),100,100,"btn8",cb_b8),
    b9(Point(50,250),100,100,"btn9",cb_b9),
    b10(Point(150,250),100,100,"btn10",cb_b10),
    b11(Point(250,250),100,100,"btn11",cb_b11),
    b12(Point(350,250),100,100,"btn12",cb_b12),
    b13(Point(50,350),100,100,"btn13",cb_b13),
    b14(Point(150,350),100,100,"btn14",cb_b14),
    b15(Point(250,350),100,100,"btn15",cb_b15),
    r1(Point(50,50), 100, 100),              //These are the rect creations
    r2(Point(150,50), 100, 100),
    r3(Point(250,50), 100, 100),
    r4(Point(350,50), 100, 100),
    r5(Point(50,150), 100, 100),
    r6(Point(150,150), 100, 100),
    r7(Point(250,150), 100, 100),
    r8(Point(350,150), 100, 100),
    r9(Point(50,250), 100, 100),
    r10(Point(150,250), 100, 100),
    r11(Point(250,250), 100, 100),
    r12(Point(350,250), 100, 100),
    r13(Point(50,350), 100, 100),
    r14(Point(150,350), 100, 100),
    r15(Point(250,350), 100, 100),
    r16(Point(350,350), 100, 100)
{
    //All attachments
    Window::attach(b1); Window::attach(r1);
    Window::attach(b2); Window::attach(r2);
    Window::attach(b3); Window::attach(r3);
    Window::attach(b4); Window::attach(r4);
    Window::attach(b5); Window::attach(r5);
    Window::attach(b6); Window::attach(r6);
    Window::attach(b7); Window::attach(r7);
    Window::attach(b8); Window::attach(r8);
    Window::attach(b9); Window::attach(r9);
    Window::attach(b10); Window::attach(r10);
    Window::attach(b11); Window::attach(r11);
    Window::attach(b12); Window::attach(r12);
    Window::attach(b13); Window::attach(r13);
    Window::attach(b14); Window::attach(r14);
    Window::attach(b15); Window::attach(r15);
    //Except r16. That is the invisible "empty" spot
}

//------------------------------------------------------------------------------

//Callbacks//
void Oasis::cb_b1(Address, Address pw)
{
  reference_to<Oasis>(pw).f1();
}
void Oasis::cb_b2(Address, Address pw)
{
  reference_to<Oasis>(pw).f2();
}
void Oasis::cb_b3(Address, Address pw)
{
  reference_to<Oasis>(pw).f3();
}
void Oasis::cb_b4(Address, Address pw)
{
  reference_to<Oasis>(pw).f4();
}
void Oasis::cb_b5(Address, Address pw)
{
  reference_to<Oasis>(pw).f5();
}
void Oasis::cb_b6(Address, Address pw)
{
  reference_to<Oasis>(pw).f6();
}
void Oasis::cb_b7(Address, Address pw)
{
  reference_to<Oasis>(pw).f7();
}
void Oasis::cb_b8(Address, Address pw)
{
  reference_to<Oasis>(pw).f8();
}
void Oasis::cb_b9(Address, Address pw)
{
  reference_to<Oasis>(pw).f9();
}
void Oasis::cb_b10(Address, Address pw)
{
  reference_to<Oasis>(pw).f10();
}
void Oasis::cb_b11(Address, Address pw)
{
  reference_to<Oasis>(pw).f11();
}
void Oasis::cb_b12(Address, Address pw)
{
  reference_to<Oasis>(pw).f12();
}
void Oasis::cb_b13(Address, Address pw)
{
  reference_to<Oasis>(pw).f13();
}
void Oasis::cb_b14(Address, Address pw)
{
  reference_to<Oasis>(pw).f14();
}
void Oasis::cb_b15(Address, Address pw)
{
  reference_to<Oasis>(pw).f15();
}
//------------------------------------------------------------------------------

//Functions//
void Oasis::f1()
{
  boo1 = !boo1;
  if(boo1 == true)
    r1.set_fill_color(Color::red);
  else if(boo1 == false)
    r1.set_fill_color(Color::black);
  redraw();
}
void Oasis::f2()
{
  boo2 = !boo2;
  if(boo2 == true)
    r2.set_fill_color(Color::blue);
  else if(boo2 == false)
    r2.set_fill_color(Color::black);
  redraw();
}
void Oasis::f3()
{
  boo3 = !boo3;
  if(boo3 == true)
    r3.set_fill_color(Color::green);
  else if(boo3 == false)
    r3.set_fill_color(Color::black);
  redraw();
}
void Oasis::f4()
{
  boo4 = !boo4;
  if(boo4 == true)
    r4.set_fill_color(Color::yellow);
  else if(boo4 == false)
    r4.set_fill_color(Color::black);
  redraw();
}
void Oasis::f5()
{
  boo5 = !boo5;
  if(boo5 == true)
    r5.set_fill_color(Color::white);
  else if(boo5 == false)
    r5.set_fill_color(Color::black);
  redraw();
}
void Oasis::f6()
{
  boo6 = !boo6;
  if(boo6 == true)
    r6.set_fill_color(Color::magenta);
  else if(boo6 == false)
    r6.set_fill_color(Color::black);
  redraw();
}
void Oasis::f7()
{
  boo7 = !boo7;
  if(boo7 == true)
    r7.set_fill_color(Color::cyan);
  else if(boo7 == false)
    r7.set_fill_color(Color::black);
  redraw();
}
void Oasis::f8()
{
  boo8 = !boo8;
  if(boo8 == true)
    r8.set_fill_color(Color::dark_red);
  else if(boo8 == false)
    r8.set_fill_color(Color::black);
  redraw();
}
void Oasis::f9()
{
  boo9 = !boo9;
  if(boo9 == true)
    r9.set_fill_color(Color::dark_green);
  else if(boo9 == false)
    r9.set_fill_color(Color::black);
  redraw();
}
void Oasis::f10()
{
  boo10 = !boo10;
  if(boo10 == true)
    r10.set_fill_color(Color::dark_yellow);
  else if(boo10 == false)
    r10.set_fill_color(Color::black);
  redraw();
}
void Oasis::f11()
{
  boo11 = !boo11;
  if(boo11 == true)
    r11.set_fill_color(Color::dark_blue);
  else if(boo11 == false)
    r11.set_fill_color(Color::black);
  redraw();
}
void Oasis::f12()
{
  boo12 = !boo12;
  if(boo12 == true)
    r12.set_fill_color(Color::dark_magenta);
  else if(boo12 == false)
    r12.set_fill_color(Color::black);
  redraw();
}
void Oasis::f13()
{
  boo13 = !boo13;
  if(boo13 == true)
    r13.set_fill_color(Color::dark_cyan);
  else if(boo13 == false)
    r13.set_fill_color(Color::black);
  redraw();
}
void Oasis::f14()
{
  boo14 = !boo14;
  if(boo14 == true)
    r14.set_fill_color(Color::red);
  else if(boo14 == false)
    r14.set_fill_color(Color::black);
  redraw();
}
void Oasis::f15()
{
  boo15 = !boo15;
  if(boo15 == true)
    r15.set_fill_color(Color::blue);
  else if(boo15 == false)
    r15.set_fill_color(Color::black);
  redraw();
}
