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
  Rectangle r16,rb;
  Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15;

  //Definitions of vector point pairs
  vector<int> v1 = {50,50};vector<int> v2 = {150,50};vector<int> v3 = {250,50};
  vector<int> v4 = {350,50};vector<int> v5 = {50,150};vector<int> v6 = {150,150};
  vector<int> v7 = {250,150};vector<int> v8 = {350,150};vector<int> v9 = {50,250};
  vector<int> v10 = {150,250};vector<int> v11 = {250,250};vector<int> v12 = {350,250};
  vector<int> v13 = {50,350};vector<int> v14 = {150,350};vector<int> v15 = {250,350};
  vector<int> v16 = {350,350};

  //Note--- Consider changing the int values of the vectors above to be their
  //own varaibles instead. That way based on the difficulty chosen only those
  //variable ints will need to be configured and then the rest will fill in.

  //State variables of correct locations
  bool s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15;

  //Output string for the amount of correct locations with it's counter
  int cloc = 0;

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

  //Images
  //Image backgnd{Point(0,0),"manydots.jpg"};
  Image onei{Point(v1[0],v1[1]),"one.jpg"};
  Image twoi{Point(v2[0],v2[1]),"two.jpg"};
  Image threei{Point(v3[0],v3[1]),"three.jpg"};
  Image fouri{Point(v4[0],v4[1]),"four.jpg"};
  Image fivei{Point(v5[0],v5[1]),"five.jpg"};
  Image sixi{Point(v6[0],v6[1]),"six.jpg"};
  Image seveni{Point(v7[0],v7[1]),"seven.jpg"};
  Image eighti{Point(v8[0],v8[1]),"eight.jpg"};
  Image ninei{Point(v9[0],v9[1]),"nine.jpg"};
  Image teni{Point(v10[0],v10[1]),"ten.jpg"};
  Image eleveni{Point(v11[0],v11[1]),"eleven.jpg"};
  Image twelvei{Point(v12[0],v12[1]),"twelve.jpg"};
  Image thirteeni{Point(v13[0],v13[1]),"thirteen.jpg"};
  Image fourteeni{Point(v14[0],v14[1]),"fourteen.jpg"};
  Image fifteeni{Point(v15[0],v15[1]),"fifteen.jpg"};

  //Outboxes
  Out_box clocstr;

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
    r16(Point(350,350), 100, 100),
    rb(Point(40,40),420,420),  //backsplash for tiles
    clocstr(Point(200,500),50,20,"Tiles not in right spot:"),
    grey(fl_rgb_color(208, 211, 212))
{
    //All attachments
    //attach(backgnd);
    attach(clocstr);
    attach(rb); rb.set_fill_color(grey);
    attach(b1);attach(b2);attach(b3);attach(b4);attach(b5);attach(b6);attach(b7);
    attach(b8);attach(b9);attach(b10);attach(b11);attach(b12);attach(b13);
    attach(b14);attach(b15);attach(onei);attach(twoi);attach(threei);
    attach(fouri);attach(fivei);attach(sixi);attach(seveni);attach(eighti);
    attach(ninei);attach(teni);attach(eleveni);attach(twelvei);attach(thirteeni);
    attach(fourteeni);attach(fifteeni);
    //Except r16. That is the invisible "empty" spot

    //Determining the state bool vals for all tiles. The values will always be
    //these because all tiles in any difficulty will always end up in this
    //configuration.
    if((v1[0]==50)&&(v1[1]==50))
      s1 = true;
    else
    {
      s1 = false;
      cloc++;
    }
    if((v2[0]==150)&&(v2[1]==50))
      s2 = true;
    else
    {
      s2 = false;
      cloc++;
    }
    if((v3[0]==250)&&(v3[1]==50))
      s3 = true;
    else
    {
      s3 = false;
      cloc++;
    }
    if((v4[0]==350)&&(v4[1]==50))
      s4 = true;
    else
    {
      s4 = false;
      cloc++;
    }
    if((v5[0]==50)&&(v5[1]==150))
      s5 = true;
    else
    {
      s5 = false;
      cloc++;
    }
    if((v6[0]==150)&&(v6[1]==150))
      s6 = true;
    else
    {
      s6 = false;
      cloc++;
    }
    if((v7[0]==250)&&(v7[1]==150))
      s7 = true;
    else
    {
      s7 = false;
      cloc++;
    }
    if((v8[0]==350)&&(v8[1]==150))
      s8 = true;
    else
    {
      s8 = false;
      cloc++;
    }
    if((v9[0]==50)&&(v9[1]==250))
      s9 = true;
    else
    {
      s9 = false;
      cloc++;
    }
    if((v10[0]==150)&&(v10[1]==250))
      s10 = true;
    else
    {
      s10 = false;
      cloc++;
    }
    if((v11[0]==250)&&(v11[1]==250))
      s11 = true;
    else
    {
      s11 = false;
      cloc++;
    }
    if((v12[0]==350)&&(v12[1]==250))
      s12 = true;
    else
    {
      s12 = false;
      cloc++;
    }
    if((v13[0]==50)&&(v13[1]==350))
      s13 = true;
    else
    {
      s13 = false;
      cloc++;
    }
    if((v14[0]==150)&&(v14[1]==350))
      s14 = true;
    else
    {
      s14 = false;
      cloc++;
    }
    if((v15[0]==250)&&(v15[1]==350))
      s15 = true;
    else
    {
      s15 = false;
      cloc++;
    }
    //fill in here for rest of tiles
    ostringstream oss;
    oss << cloc;
    clocstr.put(oss.str());
    redraw();
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
    onei.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v1 = v16;
    v16 = temp;
  }
  if(((v1[0]==50)&&(v1[1]==50)) && (s1 == false))
  {
    s1 = true;
    --cloc;
  }
  if(((v1[0]!=50)||(v1[1]!=50)) && (s1 == true))
  {
    s1 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    twoi.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v2 = v16;
    v16 = temp;
  }
  if(((v2[0]==150)&&(v2[1]==50)) && (s2 == false))
  {
    s2 = true;
    --cloc;
  }
  if(((v2[0]!=150)||(v2[1]!=50)) && (s2 == true))
  {
    s2 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    threei.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v3 = v16;
    v16 = temp;
  }
  if(((v3[0]==250)&&(v3[1]==50)) && (s3 == false))
  {
    s3 = true;
    --cloc;
  }
  if(((v3[0]!=250)||(v3[1]!=50)) && (s3 == true))
  {
    s3 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    fouri.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v4 = v16;
    v16 = temp;
  }
  if(((v4[0]==350)&&(v4[1]==50)) && (s4 == false))
  {
    s4 = true;
    --cloc;
  }
  if(((v4[0]!=350)||(v4[1]!=50)) && (s4 == true))
  {
    s4 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    fivei.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v5 = v16;
    v16 = temp;
  }
  if(((v5[0]==50)&&(v5[1]==150)) && (s5 == false))
  {
    s5 = true;
    --cloc;
  }
  if(((v5[0]!=50)||(v5[1]!=150)) && (s5 == true))
  {
    s5 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    sixi.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v6 = v16;
    v16 = temp;
  }
  if(((v6[0]==150)&&(v6[1]==150)) && (s6 == false))
  {
    s6 = true;
    --cloc;
  }
  if(((v6[0]!=150)||(v6[1]!=150)) && (s6 == true))
  {
    s6 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    seveni.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v7 = v16;
    v16 = temp;
  }
  if(((v7[0]==250)&&(v7[1]==150)) && (s7 == false))
  {
    s7 = true;
    --cloc;
  }
  if(((v7[0]!=250)||(v7[1]!=150)) && (s7 == true))
  {
    s7 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    eighti.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v8 = v16;
    v16 = temp;
  }
  if(((v8[0]==350)&&(v8[1]==150)) && (s8 == false))
  {
    s8 = true;
    --cloc;
  }
  if(((v8[0]!=350)||(v8[1]!=150)) && (s8 == true))
  {
    s8 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    ninei.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v9 = v16;
    v16 = temp;
  }
  if(((v9[0]==50)&&(v1[1]==250)) && (s9 == false))
  {
    s9 = true;
    --cloc;
  }
  if(((v9[0]!=50)||(v9[1]!=250)) && (s9 == true))
  {
    s9 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    teni.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v10 = v16;
    v16 = temp;
  }
  if(((v10[0]==150)&&(v10[1]==250)) && (s10 == false))
  {
    s10 = true;
    --cloc;
  }
  if(((v10[0]!=150)||(v10[1]!=250)) && (s10 == true))
  {
    s10 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    eleveni.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v11 = v16;
    v16 = temp;
  }
  if(((v11[0]==250)&&(v11[1]==250)) && (s11 == false))
  {
    s11 = true;
    --cloc;
  }
  if(((v11[0]!=250)||(v11[1]!=250)) && (s11 == true))
  {
    s11 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    twelvei.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v12 = v16;
    v16 = temp;
  }
  if(((v12[0]==350)&&(v12[1]==250)) && (s12 == false))
  {
    s12 = true;
    --cloc;
  }
  if(((v12[0]!=350)||(v12[1]!=250)) && (s12 == true))
  {
    s12 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    thirteeni.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v13 = v16;
    v16 = temp;
  }
  if(((v13[0]==50)&&(v13[1]==350)) && (s13 == false))
  {
    s13 = true;
    --cloc;
  }
  if(((v13[0]!=50)||(v13[1]!=350)) && (s13 == true))
  {
    s13 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    fourteeni.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v14 = v16;
    v16 = temp;
  }
  if(((v14[0]==150)&&(v14[1]==350)) && (s14 == false))
  {
    s14 = true;
    --cloc;
  }
  if(((v14[0]!=150)||(v14[1]!=350)) && (s14 == true))
  {
    s14 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
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
    fifteeni.move(mvx[0],mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v15 = v16;
    v16 = temp;
  }
  if(((v15[0]==250)&&(v15[1]==350)) && (s15 == false))
  {
    s15 = true;
    --cloc;
  }
  if(((v15[0]!=250)||(v15[1]!=350)) && (s15 == true))
  {
    s15 = false;
    ++cloc;
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
  redraw();
}
