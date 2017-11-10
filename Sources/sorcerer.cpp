#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Point.h"
#include "Window.h"
#include <vector>

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Oasis : Graph_lib::Window
{
    Oasis(Point xy, int w, int h, const string& title);

private:
  //Declaring all items. Rectangle and Button pairs
  Rectangle r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,rb;
  Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15;

  //Main vector to hold vector point pairs
  //Definitions of vector point pairs
  vector<int> v1 = {50,50};vector<int> v2 = {150,50};vector<int> v3 = {250,50};
  vector<int> v4 = {350,50};vector<int> v5 = {50,150};vector<int> v6 = {150,150};
  vector<int> v7 = {250,150};vector<int> v8 = {350,150};vector<int> v9 = {50,250};
  vector<int> v10 = {150,250};vector<int> v11 = {250,250};vector<int> v12 = {350,250};
  vector<int> v13 = {50,350};vector<int> v14 = {150,350};vector<int> v15 = {250,350};
  vector<int> v16 = {350,350};

  //temporary vectors used when moving pairs
  vector<int> mvx = {0,0};
  vector<int> mvy = {0,0};
  vector<int> mvX = {0,0};
  vector<int> mvY = {0,0};
  vector<int> temp = {0,0};

  //Declaring the callbacks
  static void cb_b1(Address, Address);static void cb_b2(Address, Address);
  static void cb_b3(Address, Address);static void cb_b4(Address, Address);
  static void cb_b5(Address, Address);static void cb_b6(Address, Address);
  static void cb_b7(Address, Address);static void cb_b8(Address, Address);
  static void cb_b9(Address, Address);static void cb_b10(Address, Address);
  static void cb_b11(Address, Address);static void cb_b12(Address, Address);
  static void cb_b13(Address, Address);static void cb_b14(Address, Address);
  static void cb_b15(Address, Address);

  //Declaring the functions
  void f1();void f2();void f3();void f4();void f5();void f6();void f7();
  void f8();void f9();void f10();void f11();void f12();void f13();void f14();
  void f15();

  //Background image
  Image backgnd{Point(0,0),"manydots.jpg"};

  //Colors
  Color grey;
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
    r16(Point(350,350), 100, 100),
    rb(Point(40,40),420,420),
    grey(fl_rgb_color(128,128,128))
{
    //All attachments
    attach(backgnd);
    attach(rb); rb.set_fill_color(grey);
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
  if(((((v16[0]==v1[0]-100)||(v16[0]==v1[0]+100))&&(v16[1]==v1[1])))
  ||((((v16[1]==v1[1]-100)||(v16[1]==v1[1]+100))&&(v16[0]==v1[0]))))
  {
    temp = v1;
    mvx[0] = v16[0] - v1[0];
    mvy[1] = v16[1] - v1[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b1.move(mvx[0],mvy[1]);
    r1.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v1 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f2()
{
  if(((((v16[0]==v2[0]-100)||(v16[0]==v2[0]+100))&&(v16[1]==v2[1])))
  ||((((v16[1]==v2[1]-100)||(v16[1]==v2[1]+100))&&(v16[0]==v2[0]))))
  {
    temp = v2;
    mvx[0] = v16[0] - v2[0];
    mvy[1] = v16[1] - v2[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b2.move(mvx[0],mvy[1]);
    r2.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v2 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f3()
{
  if(((((v16[0]==v3[0]-100)||(v16[0]==v3[0]+100))&&(v16[1]==v3[1])))
  ||((((v16[1]==v3[1]-100)||(v16[1]==v3[1]+100))&&(v16[0]==v3[0]))))
  {
    temp = v3;
    mvx[0] = v16[0] - v3[0];
    mvy[1] = v16[1] - v3[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b3.move(mvx[0],mvy[1]);
    r3.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v3 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f4()
{
  if(((((v16[0]==v4[0]-100)||(v16[0]==v4[0]+100))&&(v16[1]==v4[1])))
  ||((((v16[1]==v4[1]-100)||(v16[1]==v4[1]+100))&&(v16[0]==v4[0]))))
  {
    temp = v4;
    mvx[0] = v16[0] - v4[0];
    mvy[1] = v16[1] - v4[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b4.move(mvx[0],mvy[1]);
    r4.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v4 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f5()
{
  if(((((v16[0]==v5[0]-100)||(v16[0]==v5[0]+100))&&(v16[1]==v5[1])))
  ||((((v16[1]==v5[1]-100)||(v16[1]==v5[1]+100))&&(v16[0]==v5[0]))))
  {
    temp = v5;
    mvx[0] = v16[0] - v5[0];
    mvy[1] = v16[1] - v5[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b5.move(mvx[0],mvy[1]);
    r5.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v5 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f6()
{
  if(((((v16[0]==v6[0]-100)||(v16[0]==v6[0]+100))&&(v16[1]==v6[1])))
  ||((((v16[1]==v6[1]-100)||(v16[1]==v6[1]+100))&&(v16[0]==v6[0]))))
  {
    temp = v6;
    mvx[0] = v16[0] - v6[0];
    mvy[1] = v16[1] - v6[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b6.move(mvx[0],mvy[1]);
    r6.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v6 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f7()
{
  if(((((v16[0]==v7[0]-100)||(v16[0]==v7[0]+100))&&(v16[1]==v7[1])))
  ||((((v16[1]==v7[1]-100)||(v16[1]==v7[1]+100))&&(v16[0]==v7[0]))))
  {
    temp = v7;
    mvx[0] = v16[0] - v7[0];
    mvy[1] = v16[1] - v7[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b7.move(mvx[0],mvy[1]);
    r7.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v7 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f8()
{
  if(((((v16[0]==v8[0]-100)||(v16[0]==v8[0]+100))&&(v16[1]==v8[1])))
  ||((((v16[1]==v8[1]-100)||(v16[1]==v8[1]+100))&&(v16[0]==v8[0]))))
  {
    temp = v8;
    mvx[0] = v16[0] - v8[0];
    mvy[1] = v16[1] - v8[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b8.move(mvx[0],mvy[1]);
    r8.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v8 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f9()
{
  if(((((v16[0]==v9[0]-100)||(v16[0]==v9[0]+100))&&(v16[1]==v9[1])))
  ||((((v16[1]==v9[1]-100)||(v16[1]==v9[1]+100))&&(v16[0]==v9[0]))))
  {
    temp = v9;
    mvx[0] = v16[0] - v9[0];
    mvy[1] = v16[1] - v9[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b9.move(mvx[0],mvy[1]);
    r9.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v9 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f10()
{
  if(((((v16[0]==v10[0]-100)||(v16[0]==v10[0]+100))&&(v16[1]==v10[1])))
  ||((((v16[1]==v10[1]-100)||(v16[1]==v10[1]+100))&&(v16[0]==v10[0]))))
  {
    temp = v10;
    mvx[0] = v16[0] - v10[0];
    mvy[1] = v16[1] - v10[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b10.move(mvx[0],mvy[1]);
    r10.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v10 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f11()
{
  if(((((v16[0]==v11[0]-100)||(v16[0]==v11[0]+100))&&(v16[1]==v11[1])))
  ||((((v16[1]==v11[1]-100)||(v16[1]==v11[1]+100))&&(v16[0]==v11[0]))))
  {
    temp = v11;
    mvx[0] = v16[0] - v11[0];
    mvy[1] = v16[1] - v11[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b11.move(mvx[0],mvy[1]);
    r11.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v11 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f12()
{
  if(((((v16[0]==v12[0]-100)||(v16[0]==v12[0]+100))&&(v16[1]==v12[1])))
  ||((((v16[1]==v12[1]-100)||(v16[1]==v12[1]+100))&&(v16[0]==v12[0]))))
  {
    temp = v12;
    mvx[0] = v16[0] - v12[0];
    mvy[1] = v16[1] - v12[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b12.move(mvx[0],mvy[1]);
    r12.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v12 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f13()
{
  if(((((v16[0]==v13[0]-100)||(v16[0]==v13[0]+100))&&(v16[1]==v13[1])))
  ||((((v16[1]==v13[1]-100)||(v16[1]==v13[1]+100))&&(v16[0]==v13[0]))))
  {
    temp = v13;
    mvx[0] = v16[0] - v13[0];
    mvy[1] = v16[1] - v13[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b13.move(mvx[0],mvy[1]);
    r13.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v13 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f14()
{
  if(((((v16[0]==v14[0]-100)||(v16[0]==v14[0]+100))&&(v16[1]==v14[1])))
  ||((((v16[1]==v14[1]-100)||(v16[1]==v14[1]+100))&&(v16[0]==v14[0]))))
  {
    temp = v14;
    mvx[0] = v16[0] - v14[0];
    mvy[1] = v16[1] - v14[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b14.move(mvx[0],mvy[1]);
    r14.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v14 = v16;
    v16 = temp;
  }
  redraw();
}
void Oasis::f15()
{
  if(((((v16[0]==v15[0]-100)||(v16[0]==v15[0]+100))&&(v16[1]==v15[1])))
  ||((((v16[1]==v15[1]-100)||(v16[1]==v15[1]+100))&&(v16[0]==v15[0]))))
  {
    temp = v15;
    mvx[0] = v16[0] - v15[0];
    mvy[1] = v16[1] - v15[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b15.move(mvx[0],mvy[1]);
    r15.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v15 = v16;
    v16 = temp;
  }
  redraw();
}
