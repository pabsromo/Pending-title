#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Point.h"
#include "Window.h"
#include <vector>

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

struct Oasis : Graph_lib::Window
{
    Oasis(Point xy, int w, int h, const string& title);
    int diffLev = 0;
    void checklevel();
private:
  //Declaring all items. Rectangle and Button pairs and Tile images
  Image red1, red2, red3, red4, red5, red6, red7, red8, red9, red10, red11, red12, red13, red14, red15;
  Image green1, green2, green3, green4, green5, green6, green7, green8, green9, green10, green11, green12, green13, green14, green15;

  Rectangle r16,rb;
  Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,bH;

  //bools
  bool s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15;
  int nstep = 0;

  //Definitions of vector point pairs
  vector<int> v1 = {50,50};vector<int> v2 = {150,50};vector<int> v3 = {250,50};
  vector<int> v4 = {350,50};vector<int> v5 = {50,150};vector<int> v6 = {150,150};
  vector<int> v7 = {250,150};vector<int> v8 = {350,150};vector<int> v9 = {50,250};
  vector<int> v10 = {150,250};vector<int> v11 = {250,250};vector<int> v12 = {350,250};
  vector<int> v13 = {50,350};vector<int> v14 = {150,350};vector<int> v15 = {250,350};
  vector<int> v16 = {350,350};


  // original position of numbers
  vector<int> OGv1 = { 50,50 }; vector<int> OGv2 = { 150,50 }; vector<int> OGv3 = { 250,50 };
  vector<int> OGv4 = { 350,50 }; vector<int> OGv5 = { 50,150 }; vector<int> OGv6 = { 150,150 };
  vector<int> OGv7 = { 250,150 }; vector<int> OGv8 = { 350,150 }; vector<int> OGv9 = { 50,250 };
  vector<int> OGv10 = { 150,250 }; vector<int> OGv11 = { 250,250 }; vector<int> OGv12 = { 350,250 };
  vector<int> OGv13 = { 50,350 }; vector<int> OGv14 = { 150,350 }; vector<int> OGv15 = { 250,350 };
  vector<int> OGv16 = { 350,350 };


  //temporary vectors used when moving pairs
  vector<int> mvx = {0,0};
  vector<int> mvy = {0,0};
  vector<int> mvX = {0,0};
  vector<int> mvY = {0,0};
  vector<int> temp = {0,0};
  vector<int> temp2 = {0,0};
  vector<int> upv = {0,0};
  vector<int> dnv = {0,0};
  vector<int> lftv = {0,0};
  vector<int> rtv = {0,0};

  //Output string for the amount of correct locations with it's counter
  int cloc = 0;
  int movenum = 0;
  int maxmove = 40;
  int up = 0;
  int dn = 0;
  int lft = 0;
  int rt = 0;
  string movestring;

  //Outboxes
  Out_box clocstr;
  Out_box remain;
  Out_box hints;

  //Declaring the callbacks
  static void cb_b1(Address, Address);static void cb_b2(Address, Address);
  static void cb_b3(Address, Address);static void cb_b4(Address, Address);
  static void cb_b5(Address, Address);static void cb_b6(Address, Address);
  static void cb_b7(Address, Address);static void cb_b8(Address, Address);
  static void cb_b9(Address, Address);static void cb_b10(Address, Address);
  static void cb_b11(Address, Address);static void cb_b12(Address, Address);
  static void cb_b13(Address, Address);static void cb_b14(Address, Address);
  static void cb_b15(Address, Address);static void hinter(Address, Address);

  //Declaring the functions
  void f1();void f2();void f3();void f4();void f5();void f6();void f7();
  void f8();void f9();void f10();void f11();void f12();void f13();void f14();
  void f15();void outs();void closer();
  void fhint();int mvup();int mvdn();
  int mvlft();int mvrt();
  void move1();void move2();void move3();void move4();void move5();void move6();
  void move7();void move8();void move9();void move10();void move11();
  void move12();void move13();void move14();void move15();void attach1();
  void attach2();void attach3();void attach4();void attach5();void attach6();
  void attach7();void attach8();void attach9();void attach10();void attach11();
  void attach12();void attach13();void attach14();void attach15();
  void placer(vector<int> v, vector<int> ov);void placer1();void placer2();
  void placer3();void placer4();void placer5();void placer6();void placer7();
  void placer8();void placer9();void placer10();void placer11();void placer12();
  void placer13();void placer14();void placer15();void levels();
  void step(vector<int> v1, vector<int> v2);
  void isabove(vector<int> v);void isbelow(vector<int> v);void isleft(vector<int> v);
  void isright(vector<int> v);void revert3();void revert4();
  void switchover1();void revert1();void checkstep();void revert2();
  void switchover2();void switchover3();
  void switchover4();
  void sorthint(); void hint_hider();
  //Background image
  //Image backgnd{Point(0,0),"manydots.jpg"};

  //Colors
  Color grey;
};

//------------------------------------------------------------------------------

Oasis::Oasis(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title), //making the window
	b1(Point(50, 50), 100, 100, "btn1", cb_b1),  //These are the button creations
	b2(Point(150, 50), 100, 100, "btn2", cb_b2),
	b3(Point(250, 50), 100, 100, "btn3", cb_b3),
	b4(Point(350, 50), 100, 100, "btn4", cb_b4),
	b5(Point(50, 150), 100, 100, "btn5", cb_b5),
	b6(Point(150, 150), 100, 100, "btn6", cb_b6),
	b7(Point(250, 150), 100, 100, "btn7", cb_b7),
	b8(Point(350, 150), 100, 100, "btn8", cb_b8),
	b9(Point(50, 250), 100, 100, "btn9", cb_b9),
	b10(Point(150, 250), 100, 100, "btn10", cb_b10),
	b11(Point(250, 250), 100, 100, "btn11", cb_b11),
	b12(Point(350, 250), 100, 100, "btn12", cb_b12),
	b13(Point(50, 350), 100, 100, "btn13", cb_b13),
	b14(Point(150, 350), 100, 100, "btn14", cb_b14),
	b15(Point(250, 350), 100, 100, "btn15", cb_b15),
  bH(Point(200, 550), 50, 20, "Hint", hinter),
	r16(Point(350, 350), 100, 100),
	rb(Point(40, 40), 420, 420),
  clocstr(Point(200,500),50,20,"Tiles not in right spot:"),
  remain(Point(200,525),50,20,"Remaining moves:"),
  hints(Point(100,600),300,20, ""),

	grey(fl_rgb_color(128, 128, 128)),

	red1{ Point(50, 50),"15 Puzzle Tile Images/Red 1-15/Red1Tile.jpg" },              //These are the Red Tile creations
	red2{ Point(150, 50),"15 Puzzle Tile Images/Red 1-15/Red2Tile.jpg" },
	red3{ Point(250, 50),"15 Puzzle Tile Images/Red 1-15/Red3Tile.jpg" },
	red4{ Point(350, 50),"15 Puzzle Tile Images/Red 1-15/Red4Tile.jpg" },
	red5{ Point(50, 150),"15 Puzzle Tile Images//Red 1-15//Red5Tile.jpg"},
	red6{ Point(150, 150),"15 Puzzle Tile Images/Red 1-15/Red6Tile.jpg" },
	red7{ Point(250, 150),"15 Puzzle Tile Images/Red 1-15/Red7Tile.jpg" },
	red8{ Point(350, 150),"15 Puzzle Tile Images/Red 1-15/Red8Tile.jpg" },
	red9{ Point(50, 250),"15 Puzzle Tile Images/Red 1-15/Red9Tile.jpg" },
	red10{ Point(150, 250),"15 Puzzle Tile Images/Red 1-15/Red10Tile.jpg" },
	red11{ Point(250, 250),"15 Puzzle Tile Images/Red 1-15/Red11Tile.jpg" },
	red12{ Point(350, 250),"15 Puzzle Tile Images/Red 1-15/Red12Tile.jpg" },
	red13{ Point(50, 350),"15 Puzzle Tile Images/Red 1-15/Red13Tile.jpg" },
	red14{ Point(150, 350),"15 Puzzle Tile Images/Red 1-15/Red14Tile.jpg" },
	red15{ Point(250, 350),"15 Puzzle Tile Images/Red 1-15/Red15Tile.jpg" },

	green1{ Point(50, 50),"15 Puzzle Tile Images/Green 1-15/Green1Tile.jpg" },              //These are the Green Tile creations
	green2{ Point(150, 50),"15 Puzzle Tile Images/Green 1-15/Green2Tile.jpg" },
	green3{ Point(250, 50),"15 Puzzle Tile Images/Green 1-15/Green3Tile.jpg" },
	green4{ Point(350, 50),"15 Puzzle Tile Images/Green 1-15/Green4Tile.jpg" },
	green5{ Point(50, 150),"15 Puzzle Tile Images/Green 1-15/Green5Tile.jpg" },
	green6{ Point(150, 150),"15 Puzzle Tile Images/Green 1-15/Green6Tile.jpg" },
	green7{ Point(250, 150),"15 Puzzle Tile Images/Green 1-15/Green7Tile.jpg" },
	green8{ Point(350, 150),"15 Puzzle Tile Images/Green 1-15/Green8Tile.jpg" },
	green9{ Point(50, 250),"15 Puzzle Tile Images/Green 1-15/Green9Tile.jpg" },
	green10{ Point(150, 250),"15 Puzzle Tile Images/Green 1-15/Green10Tile.jpg" },
	green11{ Point(250, 250),"15 Puzzle Tile Images/Green 1-15/Green11Tile.jpg" },
	green12{ Point(350, 250),"15 Puzzle Tile Images/Green 1-15/Green12Tile.jpg" },
	green13{ Point(50, 350),"15 Puzzle Tile Images/Green 1-15/Green13Tile.jpg" },
	green14{ Point(150, 350),"15 Puzzle Tile Images/Green 1-15/Green14Tile.jpg" },
	green15{ Point(250, 350),"15 Puzzle Tile Images/Green 1-15/Green15Tile.jpg" }

{
    //All attachments
    //attach(backgnd);
    attach(clocstr);
    attach(remain);
    attach(rb); rb.set_fill_color(grey);attach(hints);
    attach(b1);attach(b2);attach(b3);attach(b4);attach(b5);attach(b6);
    attach(b7);attach(b8);attach(b9);attach(b10);attach(b11);attach(b12);
    attach(b13);attach(b14);attach(b15);attach(bH);
    //Except r16. That is the invisible "empty" spot
    s1 = true;s2 = true;s3=true;s4=true;s5=true;s6=true;s7=true;s8=true;
    s9=true;s10=true;s11=true;s12=true;s13=true;s14=true;s15=true;
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
void Oasis::hinter(Address, Address pw)
{
  reference_to<Oasis>(pw).fhint();
}

//------------------------------------------------------------------------------

//Functions//
void Oasis::outs()
{
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
  ostringstream oss2;
  oss2 << maxmove - movenum;
  remain.put(oss2.str());
  redraw();
}
void Oasis::closer()
{
  if(movenum > maxmove)
    hide();
}
void Oasis::placer(vector<int> v, vector<int> ov)
{
  mvx[0] = v[0] - ov[0];
  mvy[1] = v[1] - ov[1];
}
void Oasis::placer1()
{
  placer(v1,OGv1);
  b1.move(mvx[0],mvy[1]);
  red1.move(mvx[0], mvy[1]);
  green1.move(mvx[0], mvy[1]);
  //step(v1,OGv1);
  attach1();
}
void Oasis::placer2()
{
  placer(v2,OGv2);
  b2.move(mvx[0],mvy[1]);
  red2.move(mvx[0], mvy[1]);
  green2.move(mvx[0], mvy[1]);
  //step(v2,OGv2);
  attach2();
}
void Oasis::placer3()
{
  placer(v3,OGv3);
  b3.move(mvx[0],mvy[1]);
  red3.move(mvx[0], mvy[1]);
  green3.move(mvx[0], mvy[1]);
  //step(v3,OGv3);
  attach3();
}
void Oasis::placer4()
{
  placer(v4,OGv4);
  b4.move(mvx[0],mvy[1]);
  red4.move(mvx[0], mvy[1]);
  green4.move(mvx[0], mvy[1]);
  //step(v4,OGv4);
  attach4();
}
void Oasis::placer5()
{
  placer(v5,OGv5);
  b5.move(mvx[0],mvy[1]);
  red5.move(mvx[0], mvy[1]);
  green5.move(mvx[0], mvy[1]);
  //step(v4,OGv5);
  attach5();
}
void Oasis::placer6()
{
  placer(v6,OGv6);
  b6.move(mvx[0],mvy[1]);
  red6.move(mvx[0], mvy[1]);
  green6.move(mvx[0], mvy[1]);
  //step(v6,OGv6);
  attach6();
}
void Oasis::placer7()
{
  placer(v7,OGv7);
  b7.move(mvx[0],mvy[1]);
  red7.move(mvx[0], mvy[1]);
  green7.move(mvx[0], mvy[1]);
  //step(v7,OGv7);
  attach7();
}
void Oasis::placer8()
{
  placer(v8,OGv8);
  b8.move(mvx[0],mvy[1]);
  red8.move(mvx[0], mvy[1]);
  green8.move(mvx[0], mvy[1]);
  //step(v8,OGv8);
  attach8();
}
void Oasis::placer9()
{
  placer(v9,OGv9);
  b9.move(mvx[0],mvy[1]);
  red9.move(mvx[0], mvy[1]);
  green9.move(mvx[0], mvy[1]);
  //step(v9,OGv9);
  attach9();
}
void Oasis::placer10()
{
  placer(v10,OGv10);
  b10.move(mvx[0],mvy[1]);
  red10.move(mvx[0], mvy[1]);
  green10.move(mvx[0], mvy[1]);
  //step(v10,OGv10);
  attach10();
}
void Oasis::placer11()
{
  placer(v11,OGv11);
  b11.move(mvx[0],mvy[1]);
  red11.move(mvx[0], mvy[1]);
  green11.move(mvx[0], mvy[1]);
  //step(v11,OGv11);
  attach11();
}
void Oasis::placer12()
{
  placer(v12,OGv12);
  b12.move(mvx[0],mvy[1]);
  red12.move(mvx[0], mvy[1]);
  green12.move(mvx[0], mvy[1]);
  //step(v12,OGv12);
  attach12();
}
void Oasis::placer13()
{
  placer(v13,OGv13);
  b13.move(mvx[0],mvy[1]);
  red13.move(mvx[0], mvy[1]);
  green13.move(mvx[0], mvy[1]);
  //step(v13,OGv13);
  attach13();
}
void Oasis::placer14()
{
  placer(v14,OGv14);
  b14.move(mvx[0],mvy[1]);
  red14.move(mvx[0], mvy[1]);
  green14.move(mvx[0], mvy[1]);
  //step(v14,OGv14);
  attach14();
}
void Oasis::placer15()
{
  placer(v15,OGv15);
  b15.move(mvx[0],mvy[1]);
  red15.move(mvx[0], mvy[1]);
  green15.move(mvx[0], mvy[1]);
  //step(v15,OGv15);
  attach15();
}
void Oasis::levels()
{
  if(diffLev == 1)
  {
    v1 = {50,50};v2 = {150,50};v3 = {250,50};
    v4 = {350,50};v5 = {50,150};v6 = {150,150};
    v7 = {350,150};v8 = {250,350};v9 = {50,250};
    v10 = {150,250};v11 = {350,350};v12 = {250,150};
    v13 = {50,350};v14 = {150,350};v15 = {350,250};
    v16 = {250,250};cloc=10;
  }
  else if(diffLev == 2)
  {
    v1 = {50,50};v2 = {250,150};v3 = {250,50};
    v4 = {350,50};v5 = {50,150};v6 = {150,50};
    v7 = {350,250};v8 = {350,350};v9 = {50,250};
    v10 = {150,250};v11 = {350,150};v12 = {250,350};
    v13 = {50,350};v14 = {250,250};v15 = {150,350};
    v16 = {150,150};cloc=7;
  }
  else if(diffLev == 3)
  {
    v1 = {250,250};v2 = {150,250};v3 = {50,150};
    v4 = {50,50};v5 = {250,350};v6 = {350,350};
    v7 = {250,150};v8 = {150,50};v9 = {50,250};
    v10 = {350,250};v11 = {350,150};v12 = {250,50};
    v13 = {50,350};v14 = {150,350};v15 = {350,50};
    v16 = {150,150};cloc=4;
  }
  else if(diffLev == 4)
  {
    v1 = {350,350};v2 = {350,250};v3 = {50,250};
    v4 = {50,350};v5 = {250,350};v6 = {250,250};
    v7 = {150,250};v8 = {150,350};v9 = {350,150};
    v10 = {250,150};v11 = {250,50};v12 = {150,50};
    v13 = {350,50};v14 = {150,150};v15 = {50,150};
    v16 = {50,50};
  }
}
void Oasis::checklevel()
{
  levels();
  placer1();
  placer2();
  placer3();
  placer4();
  placer5();
  placer6();
  placer7();
  placer8();
  placer9();
  placer10();
  placer11();
  placer12();
  placer13();
  placer14();
  placer15();
  outs();
}
void Oasis::step(vector<int> vec, vector<int> vecc)
{
  nstep = nstep + abs(vecc[0]-vec[0])/100; //x coordinate
  nstep = nstep + abs(vecc[1]-vec[1])/100; //y coordinate
}
void Oasis::isabove(vector<int> v)
{
  if((v16[0]==v[0]) && (v16[1]==v[1]+100) && up == 0)
  {
    switchover1();
  }
}
void Oasis::isbelow(vector<int> v)
{
  if((v16[0]==v[0]) && (v16[1]==v[1]-100) && dn == 0)
  {
    switchover2();
  }
}
void Oasis::isleft(vector<int> v)
{
  if((v16[0]==v[0]+100) && (v16[1]==v[1]) && lft == 0)
  {
    switchover3();
  }
}
void Oasis::isright(vector<int> v)
{
  if((v16[0]==v[0]-100) && (v16[1]==v[1]) && rt == 0)
  {
    switchover4();
  }
}
void Oasis::switchover1()
{
  if((v16[0]==v1[0]) && (v16[1]==v1[1]+100) && up == 0){temp = v1;upv = v16;v1 = v16;v16 = temp;up = 1;}
  if((v16[0]==v2[0]) && (v16[1]==v2[1]+100) && up == 0){temp = v2;upv = v16;v2 = v16;v16 = temp;up = 1;}
  if((v16[0]==v3[0]) && (v16[1]==v3[1]+100) && up == 0){temp = v3;upv = v16;v3 = v16;v16 = temp;up = 1;}
  if((v16[0]==v4[0]) && (v16[1]==v4[1]+100) && up == 0){temp = v4;upv = v16;v4 = v16;v16 = temp;up = 1;}
  if((v16[0]==v5[0]) && (v16[1]==v5[1]+100) && up == 0){temp = v5;upv = v16;v5 = v16;v16 = temp;up = 1;}
  if((v16[0]==v6[0]) && (v16[1]==v6[1]+100) && up == 0){temp = v6;upv = v16;v6 = v16;v16 = temp;up = 1;}
  if((v16[0]==v7[0]) && (v16[1]==v7[1]+100) && up == 0){temp = v7;upv = v16;v7 = v16;v16 = temp;up = 1;}
  if((v16[0]==v8[0]) && (v16[1]==v8[1]+100) && up == 0){temp = v8;upv = v16;v8 = v16;v16 = temp;up = 1;}
  if((v16[0]==v9[0]) && (v16[1]==v9[1]+100) && up == 0){temp = v9;upv = v16;v9 = v16;v16 = temp;up = 1;}
  if((v16[0]==v10[0]) && (v16[1]==v10[1]+100) && up == 0){temp = v10;upv = v16;v10 = v16;v16 = temp;up = 1;}
  if((v16[0]==v11[0]) && (v16[1]==v11[1]+100) && up == 0){temp = v11;upv = v16;v11 = v16;v16 = temp;up = 1;}
  if((v16[0]==v12[0]) && (v16[1]==v12[1]+100) && up == 0){temp = v12;upv = v16;v12 = v16;v16 = temp;up = 1;}
  if((v16[0]==v13[0]) && (v16[1]==v13[1]+100) && up == 0){temp = v13;upv = v16;v13 = v16;v16 = temp;up = 1;}
  if((v16[0]==v14[0]) && (v16[1]==v14[1]+100) && up == 0){temp = v14;upv = v16;v14 = v16;v16 = temp;up = 1;}
  if((v16[0]==v15[0]) && (v16[1]==v15[1]+100) && up == 0){temp = v15;upv = v16;v15 = v16;v16 = temp;up = 1;}
}
void Oasis::switchover2()
{
  if((v16[0]==v1[0]) && (v16[1]==v1[1]-100) && dn == 0){temp = v1;dnv = v16;v1 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v2[0]) && (v16[1]==v2[1]-100) && dn == 0){temp = v2;dnv = v16;v2 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v3[0]) && (v16[1]==v3[1]-100) && dn == 0){temp = v3;dnv = v16;v3 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v4[0]) && (v16[1]==v4[1]-100) && dn == 0){temp = v4;dnv = v16;v4 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v5[0]) && (v16[1]==v5[1]-100) && dn == 0){temp = v5;dnv = v16;v5 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v6[0]) && (v16[1]==v6[1]-100) && dn == 0){temp = v6;dnv = v16;v6 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v8[0]) && (v16[1]==v7[1]-100) && dn == 0){temp = v7;dnv = v16;v7 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v9[0]) && (v16[1]==v8[1]-100) && dn == 0){temp = v8;dnv = v16;v8 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v10[0]) && (v16[1]==v9[1]-100) && dn == 0){temp = v9;dnv = v16;v9 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v11[0]) && (v16[1]==v10[1]-100) && dn == 0){temp = v10;dnv = v16;v10 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v12[0]) && (v16[1]==v11[1]-100) && dn == 0){temp = v11;dnv = v16;v11 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v13[0]) && (v16[1]==v12[1]-100) && dn == 0){temp = v12;dnv = v16;v12 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v14[0]) && (v16[1]==v13[1]-100) && dn == 0){temp = v13;dnv = v16;v13 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v15[0]) && (v16[1]==v14[1]-100) && dn == 0){temp = v14;dnv = v16;v14 = v16;v16 = temp;dn = 1;}
  if((v16[0]==v16[0]) && (v16[1]==v15[1]-100) && dn == 0){temp = v15;dnv = v16;v15 = v16;v16 = temp;dn = 1;}
}
void Oasis::switchover3()
{
  if((v16[0]==v1[0]+100) && (v16[1]==v1[1] && lft == 0)){temp = v1;lftv = v16;v1 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v2[0]+100) && (v16[1]==v2[1] && lft == 0)){temp = v2;lftv = v16;v2 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v3[0]+100) && (v16[1]==v3[1] && lft == 0)){temp = v3;lftv = v16;v3 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v4[0]+100) && (v16[1]==v4[1] && lft == 0)){temp = v4;lftv = v16;v4 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v5[0]+100) && (v16[1]==v5[1] && lft == 0)){temp = v5;lftv = v16;v5 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v6[0]+100) && (v16[1]==v6[1] && lft == 0)){temp = v6;lftv = v16;v6 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v7[0]+100) && (v16[1]==v7[1] && lft == 0)){temp = v7;lftv = v16;v7 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v8[0]+100) && (v16[1]==v8[1] && lft == 0)){temp = v8;lftv = v16;v8 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v9[0]+100) && (v16[1]==v9[1] && lft == 0)){temp = v9;lftv = v16;v9 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v10[0]+100) && (v16[1]==v10[1] && lft == 0)){temp = v10;lftv = v16;v10 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v11[0]+100) && (v16[1]==v11[1] && lft == 0)){temp = v11;lftv = v16;v11 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v12[0]+100) && (v16[1]==v12[1] && lft == 0)){temp = v12;lftv = v16;v12 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v13[0]+100) && (v16[1]==v13[1] && lft == 0)){temp = v13;lftv = v16;v13 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v14[0]+100) && (v16[1]==v14[1] && lft == 0)){temp = v14;lftv = v16;v14 = v16;v16 = temp;lft = 1;}
  if((v16[0]==v15[0]+100) && (v16[1]==v15[1] && lft == 0)){temp = v15;lftv = v16;v15 = v16;v16 = temp;lft = 1;}
}
void Oasis::switchover4()
{
  if((v16[0]==v1[0]-100) && (v16[1]==v1[1] && rt == 0)){temp = v1;rtv = v16;v1 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v2[0]-100) && (v16[1]==v2[1] && rt == 0)){temp = v2;rtv = v16;v2 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v3[0]-100) && (v16[1]==v3[1] && rt == 0)){temp = v3;rtv = v16;v3 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v4[0]-100) && (v16[1]==v4[1] && rt == 0)){temp = v4;rtv = v16;v4 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v5[0]-100) && (v16[1]==v5[1] && rt == 0)){temp = v5;rtv = v16;v5 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v6[0]-100) && (v16[1]==v6[1] && rt == 0)){temp = v6;rtv = v16;v6 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v7[0]-100) && (v16[1]==v7[1] && rt == 0)){temp = v7;rtv = v16;v7 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v8[0]-100) && (v16[1]==v8[1] && rt == 0)){temp = v8;rtv = v16;v8 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v9[0]-100) && (v16[1]==v9[1] && rt == 0)){temp = v9;rtv = v16;v9 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v10[0]-100) && (v16[1]==v10[1] && rt == 0)){temp = v10;rtv = v16;v10 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v11[0]-100) && (v16[1]==v11[1] && rt == 0)){temp = v11;rtv = v16;v11 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v12[0]-100) && (v16[1]==v12[1] && rt == 0)){temp = v12;rtv = v16;v12 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v13[0]-100) && (v16[1]==v13[1] && rt == 0)){temp = v13;rtv = v16;v13 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v14[0]-100) && (v16[1]==v14[1] && rt == 0)){temp = v14;rtv = v16;v14 = v16;v16 = temp;rt = 1;}
  if((v16[0]==v15[0]-100) && (v16[1]==v15[1] && rt == 0)){temp = v15;rtv = v16;v15 = v16;v16 = temp;rt = 1;}
}
void Oasis::revert1() //brings changed vectors back
{
  if(v1 == upv){v1 = temp;v16 = upv;}
  if(v2 == upv){v2 = temp;v16 = upv;}
  if(v3 == upv){v3 = temp;v16 = upv;}
  if(v4 == upv){v4 = temp;v16 = upv;}
  if(v5 == upv){v5 = temp;v16 = upv;}
  if(v6 == upv){v6 = temp;v16 = upv;}
  if(v7 == upv){v7 = temp;v16 = upv;}
  if(v8 == upv){v8 = temp;v16 = upv;}
  if(v9 == upv){v9 = temp;v16 = upv;}
  if(v10 == upv){v10 = temp;v16 = upv;}
  if(v11 == upv){v11 = temp;v16 = upv;}
  if(v12 == upv){v12 = temp;v16 = upv;}
  if(v13 == upv){v13 = temp;v16 = upv;}
  if(v14 == upv){v14 = temp;v16 = upv;}
  if(v15 == upv){v15 = temp;v16 = upv;}
}
void Oasis::revert2() //brings changed vectors back
{
  if(v1 == dnv){v1 = temp;v16 = dnv;}
  if(v2 == dnv){v2 = temp;v16 = dnv;}
  if(v3 == dnv){v3 = temp;v16 = dnv;}
  if(v4 == dnv){v4 = temp;v16 = dnv;}
  if(v5 == dnv){v5 = temp;v16 = dnv;}
  if(v6 == dnv){v6 = temp;v16 = dnv;}
  if(v7 == dnv){v7 = temp;v16 = dnv;}
  if(v8 == dnv){v8 = temp;v16 = dnv;}
  if(v9 == dnv){v9 = temp;v16 = dnv;}
  if(v10 == dnv){v10 = temp;v16 = dnv;}
  if(v11 == dnv){v11 = temp;v16 = dnv;}
  if(v12 == dnv){v12 = temp;v16 = dnv;}
  if(v13 == dnv){v13 = temp;v16 = dnv;}
  if(v14 == dnv){v14 = temp;v16 = dnv;}
  if(v15 == dnv){v15 = temp;v16 = dnv;}
}
void Oasis::revert3() //brings changed vectors back
{
  if(v1 == lftv){v1 = temp;v16 = lftv;}
  if(v2 == lftv){v2 = temp;v16 = lftv;}
  if(v3 == lftv){v3 = temp;v16 = lftv;}
  if(v4 == lftv){v4 = temp;v16 = lftv;}
  if(v5 == lftv){v5 = temp;v16 = lftv;}
  if(v6 == lftv){v6 = temp;v16 = lftv;}
  if(v7 == lftv){v7 = temp;v16 = lftv;}
  if(v8 == lftv){v8 = temp;v16 = lftv;}
  if(v9 == lftv){v9 = temp;v16 = lftv;}
  if(v10 == lftv){v10 = temp;v16 = lftv;}
  if(v11 == lftv){v11 = temp;v16 = lftv;}
  if(v12 == lftv){v12 = temp;v16 = lftv;}
  if(v13 == lftv){v13 = temp;v16 = lftv;}
  if(v14 == lftv){v14 = temp;v16 = lftv;}
  if(v15 == lftv){v15 = temp;v16 = lftv;}
}
void Oasis::revert4() //brings changed vectors back
{
  if(v1 == rtv){v1 = temp;v16 = rtv;}
  if(v2 == rtv){v2 = temp;v16 = rtv;}
  if(v3 == rtv){v3 = temp;v16 = rtv;}
  if(v4 == rtv){v4 = temp;v16 = rtv;}
  if(v5 == rtv){v5 = temp;v16 = rtv;}
  if(v6 == rtv){v6 = temp;v16 = rtv;}
  if(v7 == rtv){v7 = temp;v16 = rtv;}
  if(v8 == rtv){v8 = temp;v16 = rtv;}
  if(v9 == rtv){v9 = temp;v16 = rtv;}
  if(v10 == rtv){v10 = temp;v16 = rtv;}
  if(v11 == rtv){v11 = temp;v16 = rtv;}
  if(v12 == rtv){v12 = temp;v16 = rtv;}
  if(v13 == rtv){v13 = temp;v16 = rtv;}
  if(v14 == rtv){v14 = temp;v16 = rtv;}
  if(v15 == rtv){v15 = temp;v16 = rtv;}
}
void Oasis::checkstep()
{
  step(v1,OGv1);step(v2,OGv2);step(v3,OGv3);step(v4,OGv4);step(v5,OGv5);step(v6,OGv6);
  step(v7,OGv7);step(v8,OGv8);step(v9,OGv9);step(v10,OGv10);step(v11,OGv11);
  step(v12,OGv12);step(v13,OGv13);step(v14,OGv14);step(v15,OGv15);
}
int Oasis::mvup()
{
  isabove(v1);isabove(v2);isabove(v3);isabove(v4);isabove(v5);isabove(v6);
  isabove(v7);isabove(v8);isabove(v9);isabove(v10);isabove(v11);isabove(v12);
  isabove(v13);isabove(v14);isabove(v15);
  if(up == 1)
  {
    checkstep();
    revert1();
    return nstep;
  } else {/*revert1();*/return 300;}
}
int Oasis::mvdn()
{
  isbelow(v1);isbelow(v2);isbelow(v3);isbelow(v4);isbelow(v5);isbelow(v6);
  isbelow(v7);isbelow(v8);isbelow(v9);isbelow(v10);isbelow(v11);isbelow(v12);
  isbelow(v13);isbelow(v14);isbelow(v15);
  if(dn == 1)
  {
    checkstep();
    revert2();
    return nstep;
  } else {/*revert2();*/return 300;}
}
int Oasis::mvlft()
{
  isleft(v1);isleft(v2);isleft(v3);isleft(v4);isleft(v5);isleft(v6);
  isleft(v7);isleft(v8);isleft(v9);isleft(v10);isleft(v11);isleft(v12);
  isleft(v13);isleft(v14);isleft(v15);
  if(lft == 1)
  {
    checkstep();
    revert3();
    return nstep;
  } else {/*revert3();*/return 300;}
}
int Oasis::mvrt()
{
  isright(v1);isright(v2);isright(v3);isright(v4);isright(v5);isright(v6);
  isright(v7);isright(v8);isright(v9);isright(v10);isright(v11);isright(v12);
  isright(v13);isright(v14);isright(v15);
  if(rt == 1)
  {
    checkstep();
    revert4();
    return nstep;
  } else {/*revert4();*/return 300;}
}
void Oasis::sorthint()
{
  temp[0] = min(up,dn);
  temp[1] = min(lft,rt);
  temp2[0] = min(temp[0],temp[1]);
  if(temp2[0] == up)
    movestring = "tile above the blank.";
  else if(temp2[0] == dn)
    movestring = "tile below the blank.";
  else if(temp2[0] == lft)
    movestring = "tile to the left of the blank.";
  else if(temp2[0] == rt)
    movestring = "tile to the right of the blank.";
}
void Oasis::fhint()
{
    up = mvup(); nstep = 0;
    dn = mvdn(); nstep = 0;
    lft = mvlft(); nstep = 0;
    rt = mvrt();
    sorthint();
    ostringstream oss;
    oss << "You should click the " << movestring;
    //oss << "up "<<up<< " dn "<<dn<<" lft "<<lft<<" rt "<<rt;
    hints.put(oss.str());
    redraw();
    up = 0; dn = 0; lft = 0; rt = 0; nstep = 0;
}
void Oasis::hint_hider()
{
  ostringstream oss;
  oss << "";
  hints.put(oss.str());
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

void Oasis::move1()
{
  if(((((v16[0]==v1[0]-100)||(v16[0]==v1[0]+100))&&(v16[1]==v1[1])))
  ||((((v16[1]==v1[1]-100)||(v16[1]==v1[1]+100))&&(v16[0]==v1[0])))){
    temp = v1;
    mvx[0] = v16[0] - v1[0];
    mvy[1] = v16[1] - v1[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b1.move(mvx[0],mvy[1]);
	  red1.move(mvx[0], mvy[1]);
	  green1.move(mvx[0], mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v1 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach1()
{
  if (OGv1 == v1){
    attach(green1);
    --cloc;
    s1 = true;
  }
  else if(s1 == true){
    attach(red1);
    ++cloc;
    s1 = false;
  }
}
void Oasis::f1()
{
  move1();
  attach1();
  closer();
  outs();
}
void Oasis::move2()
{
  if(((((v16[0]==v2[0]-100)||(v16[0]==v2[0]+100))&&(v16[1]==v2[1])))
  ||((((v16[1]==v2[1]-100)||(v16[1]==v2[1]+100))&&(v16[0]==v2[0])))){
    temp = v2;
    mvx[0] = v16[0] - v2[0];
    mvy[1] = v16[1] - v2[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b2.move(mvx[0],mvy[1]);
	  red2.move(mvx[0], mvy[1]);
	  green2.move(mvx[0], mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v2 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach2()
{
  if (OGv2 == v2){
    attach(green2);
    --cloc;
    s2 = true;
  }
  else if(s2 == true){
    attach(red2);
    ++cloc;
    s2 = false;
  }
}
void Oasis::f2()
{
  move2();
  attach2();
  closer();
  outs();
}
void Oasis::move3()
{
  if(((((v16[0]==v3[0]-100)||(v16[0]==v3[0]+100))&&(v16[1]==v3[1])))
  ||((((v16[1]==v3[1]-100)||(v16[1]==v3[1]+100))&&(v16[0]==v3[0])))){
    temp = v3;
    mvx[0] = v16[0] - v3[0];
    mvy[1] = v16[1] - v3[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b3.move(mvx[0],mvy[1]);
	  red3.move(mvx[0], mvy[1]);
	  green3.move(mvx[0], mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v3 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach3()
{
  if (OGv3 == v3){
    attach(green3);
    --cloc;
    s3 = true;
  }
  else if(s3 == true){
    attach(red3);
    ++cloc;
    s3 = false;
  }
}
void Oasis::f3()
{
  move3();
  attach3();
  closer();
  outs();
}
void Oasis::move4()
{
  if(((((v16[0]==v4[0]-100)||(v16[0]==v4[0]+100))&&(v16[1]==v4[1])))
  ||((((v16[1]==v4[1]-100)||(v16[1]==v4[1]+100))&&(v16[0]==v4[0])))){
    temp = v4;
    mvx[0] = v16[0] - v4[0];
    mvy[1] = v16[1] - v4[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b4.move(mvx[0],mvy[1]);
	  red4.move(mvx[0], mvy[1]);
	  green4.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v4 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach4()
{
  if (OGv4 == v4){
    attach(green4);
    --cloc;
    s4 = true;
  }
  else if(s4 == true){
    attach(red4);
    ++cloc;
    s4 = false;
  }
}
void Oasis::f4()
{
  move4();
  attach4();
  closer();
  outs();
}
void Oasis::move5()
{
  if(((((v16[0]==v5[0]-100)||(v16[0]==v5[0]+100))&&(v16[1]==v5[1])))
  ||((((v16[1]==v5[1]-100)||(v16[1]==v5[1]+100))&&(v16[0]==v5[0])))){
    temp = v5;
    mvx[0] = v16[0] - v5[0];
    mvy[1] = v16[1] - v5[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b5.move(mvx[0],mvy[1]);
	  red5.move(mvx[0], mvy[1]);
	  green5.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v5 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach5()
{
  if (OGv5 == v5){
    attach(green5);
    --cloc;
    s5 = true;
  }
  else if(s5 == true){
    attach(red5);
    ++cloc;
    s5 = false;
  }
}
void Oasis::f5()
{
  move5();
  attach5();
  closer();
  outs();
}
void Oasis::move6()
{
  if(((((v16[0]==v6[0]-100)||(v16[0]==v6[0]+100))&&(v16[1]==v6[1])))
  ||((((v16[1]==v6[1]-100)||(v16[1]==v6[1]+100))&&(v16[0]==v6[0])))){
    temp = v6;
    mvx[0] = v16[0] - v6[0];
    mvy[1] = v16[1] - v6[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b6.move(mvx[0],mvy[1]);
	  red6.move(mvx[0], mvy[1]);
	  green6.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v6 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach6()
{
  if (OGv6 == v6){
    attach(green6);
    --cloc;
    s6 = true;
  }
  else if(s6 == true){
    attach(red6);
    ++cloc;
    s6 = false;
  }
}
void Oasis::f6()
{
  move6();
  attach6();
  closer();
  outs();
}
void Oasis::move7()
{
  if(((((v16[0]==v7[0]-100)||(v16[0]==v7[0]+100))&&(v16[1]==v7[1])))
  ||((((v16[1]==v7[1]-100)||(v16[1]==v7[1]+100))&&(v16[0]==v7[0])))){
    temp = v7;
    mvx[0] = v16[0] - v7[0];
    mvy[1] = v16[1] - v7[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b7.move(mvx[0],mvy[1]);
	  red7.move(mvx[0], mvy[1]);
	  green7.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v7 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach7()
{
  if (OGv7 == v7){
    attach(green7);
    --cloc;
    s7 = true;
  }
  else if(s7 == true){
    attach(red7);
    ++cloc;
    s7 = false;
  }
}
void Oasis::f7()
{
  move7();
  attach7();
  closer();
  outs();
}
void Oasis::move8()
{
  if(((((v16[0]==v8[0]-100)||(v16[0]==v8[0]+100))&&(v16[1]==v8[1])))
  ||((((v16[1]==v8[1]-100)||(v16[1]==v8[1]+100))&&(v16[0]==v8[0])))){
    temp = v8;
    mvx[0] = v16[0] - v8[0];
    mvy[1] = v16[1] - v8[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b8.move(mvx[0],mvy[1]);
	  red8.move(mvx[0], mvy[1]);
	  green8.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v8 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach8()
{
  if (OGv8 == v8){
    attach(green8);
    --cloc;
    s8 = true;
  }
  else if(s8 == true){
    attach(red8);
    ++cloc;
    s8 = false;
  }
}
void Oasis::f8()
{
  move8();
  attach8();
  closer();
  outs();
}
void Oasis::move9()
{
  if(((((v16[0]==v9[0]-100)||(v16[0]==v9[0]+100))&&(v16[1]==v9[1])))
  ||((((v16[1]==v9[1]-100)||(v16[1]==v9[1]+100))&&(v16[0]==v9[0])))){
    temp = v9;
    mvx[0] = v16[0] - v9[0];
    mvy[1] = v16[1] - v9[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b9.move(mvx[0],mvy[1]);
	  red9.move(mvx[0], mvy[1]);
	  green9.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v9 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach9()
{
  if (OGv9 == v9){
    attach(green9);
    --cloc;
    s9 = true;
  }
  else if(s9 == true){
    attach(red9);
    ++cloc;
    s9 = false;
  }
}
void Oasis::f9()
{
  move9();
  attach9();
  closer();
  outs();
}
void Oasis::move10()
{
  if(((((v16[0]==v10[0]-100)||(v16[0]==v10[0]+100))&&(v16[1]==v10[1])))
  ||((((v16[1]==v10[1]-100)||(v16[1]==v10[1]+100))&&(v16[0]==v10[0])))){
    temp = v10;
    mvx[0] = v16[0] - v10[0];
    mvy[1] = v16[1] - v10[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b10.move(mvx[0],mvy[1]);
	  red10.move(mvx[0], mvy[1]);
	  green10.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v10 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach10()
{
  if (OGv10 == v10){
    attach(green10);
    --cloc;
    s10 = true;
  }
  else if(s10 == true){
    attach(red10);
    ++cloc;
    s10 = false;
  }
}
void Oasis::f10()
{
  move10();
  attach10();
  closer();
  outs();
}
void Oasis::move11()
{
  if(((((v16[0]==v11[0]-100)||(v16[0]==v11[0]+100))&&(v16[1]==v11[1])))
  ||((((v16[1]==v11[1]-100)||(v16[1]==v11[1]+100))&&(v16[0]==v11[0])))){
    temp = v11;
    mvx[0] = v16[0] - v11[0];
    mvy[1] = v16[1] - v11[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b11.move(mvx[0],mvy[1]);
	  red11.move(mvx[0], mvy[1]);
	  green11.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v11 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach11()
{
  if (OGv11 == v11){
    attach(green11);
    --cloc;
    s11 = true;
  }
  else if(s11 == true){
    attach(red11);
    ++cloc;
    s11 = false;
  }
}
void Oasis::f11()
{
  move11();
  attach11();
  closer();
  outs();
}
void Oasis::move12()
{
  if(((((v16[0]==v12[0]-100)||(v16[0]==v12[0]+100))&&(v16[1]==v12[1])))
  ||((((v16[1]==v12[1]-100)||(v16[1]==v12[1]+100))&&(v16[0]==v12[0])))){
    temp = v12;
    mvx[0] = v16[0] - v12[0];
    mvy[1] = v16[1] - v12[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b12.move(mvx[0],mvy[1]);
	  red12.move(mvx[0], mvy[1]);
	  green12.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v12 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach12()
{
  if (OGv12 == v12){
    attach(green12);
    --cloc;
    s12 = true;
  }
  else if(s12 == true){
    attach(red12);
    ++cloc;
    s12 = false;
  }
}
void Oasis::f12()
{
  move12();
  attach12();
  closer();
  outs();
}
void Oasis::move13()
{
  if(((((v16[0]==v13[0]-100)||(v16[0]==v13[0]+100))&&(v16[1]==v13[1])))
  ||((((v16[1]==v13[1]-100)||(v16[1]==v13[1]+100))&&(v16[0]==v13[0])))){
    temp = v13;
    mvx[0] = v16[0] - v13[0];
    mvy[1] = v16[1] - v13[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b13.move(mvx[0],mvy[1]);
	  red13.move(mvx[0], mvy[1]);
	  green13.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v13 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach13()
{
  if (OGv13 == v13){
    attach(green13);
    --cloc;
    s13 = true;
  }
  else if(s13 == true){
    attach(red13);
    ++cloc;
    s13 = false;
  }
}
void Oasis::f13()
{
  move13();
  attach13();
  closer();
  outs();
}
void Oasis::move14()
{
  if(((((v16[0]==v14[0]-100)||(v16[0]==v14[0]+100))&&(v16[1]==v14[1])))
  ||((((v16[1]==v14[1]-100)||(v16[1]==v14[1]+100))&&(v16[0]==v14[0])))){
    temp = v14;
    mvx[0] = v16[0] - v14[0];
    mvy[1] = v16[1] - v14[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b14.move(mvx[0],mvy[1]);
	  red14.move(mvx[0], mvy[1]);
	  green14.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v14 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach14()
{
  if (OGv14 == v14){
    attach(green14);
    --cloc;
    s14 = true;
  }
  else if(s14 == true){
    attach(red14);
    ++cloc;
    s14 = false;
  }
}
void Oasis::f14()
{
  move14();
  attach14();
  closer();
  outs();
}
void Oasis::move15()
{
  if(((((v16[0]==v15[0]-100)||(v16[0]==v15[0]+100))&&(v16[1]==v15[1])))
  ||((((v16[1]==v15[1]-100)||(v16[1]==v15[1]+100))&&(v16[0]==v15[0])))){
    temp = v15;
    mvx[0] = v16[0] - v15[0];
    mvy[1] = v16[1] - v15[1];
    mvX[0] = temp[0] - v16[0];
    mvY[1] = temp[1] - v16[1];
    b15.move(mvx[0],mvy[1]);
	  red15.move(mvx[0], mvy[1]);
	  green15.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v15 = v16;
    v16 = temp;
    movenum++;
    hint_hider();
  }
}
void Oasis::attach15()
{
  if (OGv15 == v15){
    attach(green15);
    --cloc;
    s15 = true;
  }
  else if(s15 == true){
    attach(red15);
    ++cloc;
    s15 = false;
  }
}
void Oasis::f15()
{
  move15();
  attach15();
  closer();
  outs();
}
