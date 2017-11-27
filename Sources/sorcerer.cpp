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
  //Declaring all items. Rectangle and Button pairs and Tile images
  Image red1, red2, red3, red4, red5, red6, red7, red8, red9, red10, red11, red12, red13, red14, red15;
  Image green1, green2, green3, green4, green5, green6, green7, green8, green9, green10, green11, green12, green13, green14, green15;

  Rectangle r16,rb;
  Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15;

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

  //Output string for the amount of correct locations with it's counter
  int cloc = 0;
  
  //Declaring Leaderboard
  Text leaderBoard;
  Text leader1;
  Text leader2;
  Text leader3;
  Text leader4;
  Text leader5;
  Text leaderCurrent;

  //Outboxes
  Out_box clocstr;

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
	r16(Point(350, 350), 100, 100),
	rb(Point(40, 40), 420, 420),
  clocstr(Point(200,500),50,20,"Tiles not in right spot:"),

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
	green15{ Point(250, 350),"15 Puzzle Tile Images/Green 1-15/Green15Tile.jpg" },
	leaderBoard{ Point{ 350,500 }, "LEADERBOARD" }, // Leaderboard objects
	leader1{ Point{ 350,520 }, "AAA - 9999" },
	leader2{ Point{ 350,540 }, "BBB - 8888" },
	leader3{ Point{ 350,560 }, "CCC - 7777" },
	leader4{ Point{ 350,580 }, "DDD - 6666" },
	leader5{ Point{ 350,600 }, "EEE - 5555" },
	leaderCurrent{ Point{ 350,620 }, "CSC - 5555" }


{
    //All attachments
    //attach(backgnd);
    attach(clocstr);
    attach(rb); rb.set_fill_color(grey);
	  attach(leaderBoard); attach(leader1); // Leaderboard Attachment
	  attach(leader2); attach(leader3);
	  attach(leader4); attach(leader5);
	  attach(leaderCurrent);
    attach(b1);
    attach(b2);
    attach(b3);
    attach(b4);
    attach(b5);
    attach(b6);
    attach(b7);
    attach(b8);
    attach(b9);
    attach(b10);
    attach(b11);
    attach(b12);
    attach(b13);
    attach(b14);
    attach(b15);
    //Except r16. That is the invisible "empty" spot

  // IMAGES

	if (OGv1 == v1)   // This will eventually be the initial check to see if
		attach(green1); // the numbers START in the correct position
	else
  {
		attach(red1);
    cloc++;
  }
	if (OGv2 == v2)
		attach(green2);
	else
  {
    attach(red2);
    cloc++;
  }
	if (OGv3 == v3)
		attach(green3);
	else
  {
    attach(red3);
    cloc++;
  }
	if (OGv4 == v4)
		attach(green4);
	else
  {
    attach(red4);
    cloc++;
  }
	if (OGv5 == v5)
		attach(green5);
	else
  {
    attach(red5);
    cloc++;
  }
	if (OGv6 == v6)
		attach(green6);
	else
  {
    attach(red6);
    cloc++;
  }
	if (OGv7 == v7)
		attach(green7);
	else
  {
    attach(red7);
    cloc++;
  }
	if (OGv8 == v8)
		attach(green8);
	else
  {
    attach(red8);
    cloc++;
  }
	if (OGv9 == v9)
		attach(green9);
	else
  {
    attach(red9);
    cloc++;
  }
	if (OGv10 == v10)
		attach(green10);
	else
  {
    attach(red10);
    cloc++;
  }
	if (OGv11 == v11)
		attach(green11);
	else
  {
    attach(red11);
    cloc++;
  }
	if (OGv12 == v12)
		attach(green12);
	else
  {
    attach(red12);
    cloc++;
  }
	if (OGv13 == v13)
		attach(green13);
	else
  {
    attach(red13);
    cloc++;
  }
	if (OGv14 == v14)
		attach(green14);
	else
  {
    attach(red14);
    cloc++;
  }
	if (OGv15 == v15)
		attach(green15);
	else
  {
    attach(red15);
    cloc++;
  }
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
	  red1.move(mvx[0], mvy[1]);
	  green1.move(mvx[0], mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v1 = v16;
    v16 = temp;
	   if (OGv1 == v1)
     {
       attach(green1);
       --cloc;
     }
	   else
     {
       attach(red1);
       ++cloc;
     }
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
	  red2.move(mvx[0], mvy[1]);
	  green2.move(mvx[0], mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v2 = v16;
    v16 = temp;
    if (OGv2 == v2)
    {
      attach(green2);
      --cloc;
    }
    else
    {
      attach(red2);
      ++cloc;
    }
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
	  red3.move(mvx[0], mvy[1]);
	  green3.move(mvx[0], mvy[1]);
    r16.move(mvX[0],mvY[1]);
    v3 = v16;
    v16 = temp;
    if (OGv3 == v3)
    {
      attach(green3);
      --cloc;
    }
  	else
    {
      attach(red3);
      ++cloc;
    }
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
	  red4.move(mvx[0], mvy[1]);
	  green4.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v4 = v16;
    v16 = temp;
    if (OGv4 == v4)
    {
      attach(green4);
      --cloc;
    }
  	else
    {
      attach(red4);
      ++cloc;
    }
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
	  red5.move(mvx[0], mvy[1]);
	  green5.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v5 = v16;
    v16 = temp;
    if (OGv5 == v5)
    {
      attach(green5);
      --cloc;
    }
  	else
    {
      attach(red5);
      ++cloc;
    }
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
	  red6.move(mvx[0], mvy[1]);
	  green6.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v6 = v16;
    v16 = temp;
    if (OGv6 == v6)
    {
      attach(green6);
      --cloc;
    }
  	else
    {
      attach(red6);
      ++cloc;
    }
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
	  red7.move(mvx[0], mvy[1]);
	  green7.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v7 = v16;
    v16 = temp;
    if (OGv7 == v7)
    {
      attach(green7);
      --cloc;
    }
  	else
    {
      attach(red7);
      ++cloc;
    }
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
	  red8.move(mvx[0], mvy[1]);
	  green8.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v8 = v16;
    v16 = temp;
    if (OGv8 == v8)
    {
      attach(green8);
      --cloc;
    }
  	else
    {
      attach(red8);
      ++cloc;
    }
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
	  red9.move(mvx[0], mvy[1]);
	  green9.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v9 = v16;
    v16 = temp;
    if (OGv9 == v9)
    {
      attach(green9);
      --cloc;
    }
  	else
    {
      attach(red9);
      ++cloc;
    }
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
	  red10.move(mvx[0], mvy[1]);
	  green10.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v10 = v16;
    v16 = temp;
    if (OGv10 == v10)
    {
      attach(green10);
      --cloc;
    }
  	else
    {
      attach(red10);
      ++cloc;
    }
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
	  red11.move(mvx[0], mvy[1]);
	  green11.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v11 = v16;
    v16 = temp;
    if (OGv11 == v11)
    {
      attach(green11);
      --cloc;
    }
  	else
    {
      attach(red11);
      ++cloc;
    }
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
	  red12.move(mvx[0], mvy[1]);
	  green12.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v12 = v16;
    v16 = temp;
    if (OGv12 == v12)
    {
      attach(green12);
      --cloc;
    }
    else
    {
      attach(red12);
      ++cloc;
    }
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
	  red13.move(mvx[0], mvy[1]);
	  green13.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v13 = v16;
    v16 = temp;
    if (OGv13 == v13)
    {
      attach(green13);
      --cloc;
    }
    else
    {
      attach(red13);
      ++cloc;
    }
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
	  red14.move(mvx[0], mvy[1]);
	  green14.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v14 = v16;
    v16 = temp;
    if (OGv14 == v14)
    {
      attach(green14);
      --cloc;
    }
    else
    {
      attach(red14);
      ++cloc;
    }
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
	  red15.move(mvx[0], mvy[1]);
	  green15.move(mvx[0], mvy[1]);
	  r16.move(mvX[0],mvY[1]);
    v15 = v16;
    v16 = temp;
    if (OGv15 == v15)
    {
      attach(green15);
      --cloc;
    }
    else
    {
      attach(red15);
      ++cloc;
    }
  }
  ostringstream oss;
  oss << cloc;
  clocstr.put(oss.str());
  redraw();
}
