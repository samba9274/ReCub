//2019-04-15 11:35:54

//Included Libraries
#include<iostream>
#include<fstream>
#include<cstring>

//Global Variables
const int MaxMoves=20;
int 	  k=-1;

//Global Functions Declarations
void   Default();
char   NextMove();
void   Functioner();
double Resumability();

//Classes
class Permutation
	{
	 private:
	 	char pos[54];
	 	char perm[MaxMoves];

	 public:
	 	Permutation();				//Set default solved cube.
	 	Permutation(char arr[MaxMoves]);	//Constructor called by Functioner.
	 	
	 	//Normal Notations
	 	void Up();
	 	void UpInverted();
	 	void Down();
	 	void DownInverted();
	 	void Left();
	 	void LeftInverted();
	 	void Right();
	 	void RightInverted();
	 	void Front();
	 	void FrontInverted();
	 	void Back();
	 	void BackInverted();

	 	//Slice Notations
	 	void Middle();
		void MiddleInverted();
		void Equatorial();
		void EquatorialInverted();
		void Standing();
		void StandingInverted();

		//Entire Cube Rotation Notations
		void X();
	 	void XInverted();
	 	void Y();
	 	void YInverted();
	 	void Z();
	 	void ZInverted();
	 	
	 	//Rotate Swapping
	 	void XRotate();
	 	void XInvertedRotate();
	 	void YRotate();
	 	void YInvertedRotate();
	 	void ZRotate();
	 	void ZInvertedRotate();

		//Generic Functions	 	
	 	void set();
	 	void rotate(char arr[3]);
	 	void print();
	 	void save();
	 	int  check_mirror();
	 	int  check_rotate();
	 	int  check_repeat();
	 	void check_and_save();
	};


//Main function
int main()
{
 Functioner();
 return 0;
}

//Global Function Definations
void Default()
{
 std::ofstream fout;
 fout.open("perm.dat", std::ios::trunc);
 fout<<std::endl;
 Permutation obj;
 obj.save();
 fout.close();
}

char NextMove()
{
 k++;
 if (k>=12)
  k=0;
 switch(k)
 {
  case 0:  return 'A';
  case 1:  return 'B';
  case 2:  return 'C';
  case 3:  return 'D';
  case 4:  return 'E';
  case 5:  return 'F';
  case 6:  return 'G';
  case 7:  return 'H';
  case 8:  return 'I';
  case 9:  return 'J';
  case 10: return 'K';
  case 11: return 'L';
 }
 return 'X';
}

void Functioner()
{
 int m;
 char arr[MaxMoves];
 std::ifstream fin;
 if (Resumability()<=0)
  Default();
 fin.open("perm.dat");
 fin.seekg(Resumability(), std::ios::beg);
 while (!(fin.eof()))
 {
  fin.seekg(1, std::ios::cur);
  fin.get(arr, MaxMoves+1);
  for (m=0; m<MaxMoves+1; m++)
  { 
   if (arr[m]=='0')
    break;
   else if (m==MaxMoves)
   {
    fin.close();
    exit (0);
   }
  }
  for (int i=0; i<=11; i++)
  {
   arr[m]=NextMove();
   Permutation obj(arr);
   obj.check_and_save();
  }
  fin.seekg(54, std::ios::cur);
 }
}

double Resumability()
{
 int i;
 char arr[MaxMoves];
 std::string str[2];
 std::ifstream fin;
 fin.open("perm.dat");
 fin.seekg(-(54+MaxMoves+1), std::ios::end);
 fin.get(arr, MaxMoves+1);
 for (i=0; i<MaxMoves+1; i++)
  if(arr[i]=='0')
   break;
 arr[i-1]='0';
 str[0]=arr;
 fin.seekg(1, std::ios::beg);
 while (!(fin.eof()))
 {
  fin.get(arr, MaxMoves+1);
  str[1]=arr;
  if(str[0].compare(str[1])==0)
   break;
  fin.seekg(55, std::ios::cur);
 }
 double k=fin.tellg();
 k-=1+MaxMoves;
 fin.close();
 return k;
}

//Permutation Class Function Definations
Permutation::Permutation()
{
 set();
}

Permutation::Permutation(char arr[MaxMoves])
{
 set();
 for (int n=0; n<MaxMoves; n++)
 {
  switch (arr[n])
  {
   case 'A':
   {
    Up();
    break;
   }
   case 'B':
   {
    UpInverted();
    break;
   }
   case 'C':
   {
    Down();
    break;
   }
   case 'D':
   {
    DownInverted();
    break;
   }
   case 'E':
   {
    Left();
    break;
   }
   case 'F':
   {
    LeftInverted();
    break;
   }
   case 'G':
   {
    Right();
    break;
   }
   case 'H':
   {
    RightInverted();
    break;
   }
   case 'I':
   {
    Front();
    break;
   }
   case 'J':
   {
    FrontInverted();
    break;
   }
   case 'K':
   {
    Back();
    break;
   }
   case 'L':
   {
    BackInverted();
    break;
   }
  }
  perm[n]=arr[n];
 }
}

void Permutation::Up()
{
 char temp;
 temp=pos[0], pos[0]=pos[6], pos[6]=pos[8], pos[8]=pos[2], pos[2]=temp;
 temp=pos[1], pos[1]=pos[3], pos[3]=pos[7], pos[7]=pos[5], pos[5]=temp;
 temp=pos[9], pos[9]=pos[18], pos[18]=pos[27], pos[27]=pos[36], pos[36]=temp;
 temp=pos[10], pos[10]=pos[19], pos[19]=pos[28], pos[28]=pos[37], pos[37]=temp;
 temp=pos[11], pos[11]=pos[20], pos[20]=pos[29], pos[29]=pos[38], pos[38]=temp;
}

void Permutation::UpInverted()
{
 char temp;
 temp=pos[0], pos[0]=pos[2], pos[2]=pos[8], pos[8]=pos[6], pos[6]=temp;
 temp=pos[1], pos[1]=pos[5], pos[5]=pos[7], pos[7]=pos[3], pos[3]=temp;
 temp=pos[9], pos[9]=pos[36], pos[36]=pos[27], pos[27]=pos[18], pos[18]=temp;
 temp=pos[10], pos[10]=pos[37], pos[37]=pos[28], pos[28]=pos[19], pos[19]=temp;
 temp=pos[11], pos[11]=pos[38], pos[38]=pos[29], pos[29]=pos[20], pos[20]=temp;
}

void Permutation::Down()
{
 char temp;
 temp=pos[45], pos[45]=pos[51], pos[51]=pos[53], pos[53]=pos[47], pos[47]=temp;
 temp=pos[46], pos[46]=pos[48], pos[48]=pos[52], pos[52]=pos[50], pos[50]=temp;
 temp=pos[15], pos[15]=pos[42], pos[42]=pos[33], pos[33]=pos[24], pos[24]=temp;
 temp=pos[16], pos[16]=pos[43], pos[43]=pos[34], pos[34]=pos[25], pos[25]=temp;
 temp=pos[17], pos[17]=pos[44], pos[44]=pos[35], pos[35]=pos[26], pos[26]=temp;
}

void Permutation::DownInverted()
{
 char temp;
 temp=pos[45], pos[45]=pos[47], pos[47]=pos[53], pos[53]=pos[51], pos[51]=temp;
 temp=pos[46], pos[46]=pos[50], pos[50]=pos[52], pos[52]=pos[48], pos[48]=temp;
 temp=pos[15], pos[15]=pos[24], pos[24]=pos[33], pos[33]=pos[42], pos[42]=temp;
 temp=pos[16], pos[16]=pos[25], pos[25]=pos[34], pos[34]=pos[43], pos[43]=temp;
 temp=pos[17], pos[17]=pos[26], pos[26]=pos[35], pos[35]=pos[44], pos[44]=temp;
}

void Permutation::Left()
{
 char temp;
 temp=pos[9], pos[9]=pos[15], pos[15]=pos[17], pos[17]=pos[11], pos[11]=temp;
 temp=pos[10], pos[10]=pos[12], pos[12]=pos[16], pos[16]=pos[14], pos[14]=temp;
 temp=pos[0], pos[0]=pos[44], pos[44]=pos[45], pos[45]=pos[18], pos[18]=temp;
 temp=pos[3], pos[3]=pos[41], pos[41]=pos[48], pos[48]=pos[21], pos[21]=temp;
 temp=pos[6], pos[6]=pos[38], pos[38]=pos[51], pos[51]=pos[24], pos[24]=temp;
}

void Permutation::LeftInverted()
{
 char temp;
 temp=pos[9], pos[9]=pos[11], pos[11]=pos[17], pos[17]=pos[15], pos[15]=temp;
 temp=pos[10], pos[10]=pos[14], pos[14]=pos[16], pos[16]=pos[12], pos[12]=temp;
 temp=pos[0], pos[0]=pos[18], pos[18]=pos[45], pos[45]=pos[44], pos[44]=temp;
 temp=pos[3], pos[3]=pos[21], pos[21]=pos[48], pos[48]=pos[41], pos[41]=temp;
 temp=pos[6], pos[6]=pos[24], pos[24]=pos[51], pos[51]=pos[38], pos[38]=temp;
}

void Permutation::Right()
{
 char temp;
 temp=pos[27], pos[27]=pos[33], pos[33]=pos[35], pos[35]=pos[29], pos[29]=temp;
 temp=pos[28], pos[28]=pos[30], pos[30]=pos[34], pos[34]=pos[32], pos[32]=temp;
 temp=pos[2], pos[2]=pos[20], pos[20]=pos[47], pos[47]=pos[42], pos[42]=temp;
 temp=pos[5], pos[5]=pos[23], pos[23]=pos[50], pos[50]=pos[39], pos[39]=temp;
 temp=pos[8], pos[8]=pos[26], pos[26]=pos[53], pos[53]=pos[36], pos[36]=temp;
}

void Permutation::RightInverted()
{
 char temp;
 temp=pos[27], pos[27]=pos[29], pos[29]=pos[35], pos[35]=pos[33], pos[33]=temp;
 temp=pos[28], pos[28]=pos[32], pos[32]=pos[34], pos[34]=pos[30], pos[30]=temp;
 temp=pos[2], pos[2]=pos[42], pos[42]=pos[47], pos[47]=pos[20], pos[20]=temp;
 temp=pos[5], pos[5]=pos[39], pos[39]=pos[50], pos[50]=pos[23], pos[23]=temp;
 temp=pos[8], pos[8]=pos[36], pos[36]=pos[53], pos[53]=pos[26], pos[26]=temp;
}

void Permutation::Front()
{
 char temp;
 temp=pos[18], pos[18]=pos[24], pos[24]=pos[26], pos[26]=pos[20], pos[20]=temp;
 temp=pos[19], pos[19]=pos[21], pos[21]=pos[25], pos[25]=pos[23], pos[23]=temp;
 temp=pos[6], pos[6]=pos[17], pos[17]=pos[47], pos[47]=pos[27], pos[27]=temp;
 temp=pos[7], pos[7]=pos[14], pos[14]=pos[46], pos[46]=pos[30], pos[30]=temp;
 temp=pos[8], pos[8]=pos[11], pos[11]=pos[45], pos[45]=pos[33], pos[33]=temp;
}

void Permutation::FrontInverted()
{
 char temp;
 temp=pos[18], pos[18]=pos[20], pos[20]=pos[26], pos[26]=pos[24], pos[24]=temp;
 temp=pos[19], pos[19]=pos[23], pos[23]=pos[25], pos[25]=pos[21], pos[21]=temp;
 temp=pos[6], pos[6]=pos[27], pos[27]=pos[47], pos[47]=pos[17], pos[17]=temp;
 temp=pos[7], pos[7]=pos[30], pos[30]=pos[46], pos[46]=pos[14], pos[14]=temp;
 temp=pos[8], pos[8]=pos[33], pos[33]=pos[45], pos[45]=pos[11], pos[11]=temp;
}

void Permutation::Back()
{
 char temp;
 temp=pos[36], pos[36]=pos[42], pos[42]=pos[44], pos[44]=pos[38], pos[38]=temp;
 temp=pos[37], pos[37]=pos[39], pos[39]=pos[43], pos[43]=pos[41], pos[41]=temp;
 temp=pos[0], pos[0]=pos[29], pos[29]=pos[53], pos[53]=pos[15], pos[15]=temp;
 temp=pos[1], pos[1]=pos[32], pos[32]=pos[52], pos[52]=pos[12], pos[12]=temp;
 temp=pos[2], pos[2]=pos[35], pos[35]=pos[51], pos[51]=pos[9], pos[9]=temp;
}

void Permutation::BackInverted()
{
 char temp;
 temp=pos[36], pos[36]=pos[38], pos[38]=pos[44], pos[44]=pos[42], pos[42]=temp;
 temp=pos[37], pos[37]=pos[41], pos[41]=pos[43], pos[43]=pos[39], pos[39]=temp;
 temp=pos[0], pos[0]=pos[15], pos[15]=pos[53], pos[53]=pos[29], pos[29]=temp;
 temp=pos[1], pos[1]=pos[12], pos[12]=pos[52], pos[52]=pos[32], pos[32]=temp;
 temp=pos[2], pos[2]=pos[9], pos[9]=pos[51], pos[51]=pos[35], pos[35]=temp;
}

void Permutation::Middle()
{
 char temp;
 temp=pos[1], pos[1]=pos[43], pos[43]=pos[46], pos[46]=pos[19], pos[19]=temp;
 temp=pos[4], pos[4]=pos[40], pos[40]=pos[49], pos[49]=pos[22], pos[22]=temp;
 temp=pos[7], pos[7]=pos[37], pos[37]=pos[52], pos[52]=pos[25], pos[25]=temp;
}

void Permutation::MiddleInverted()
{
 char temp;
 temp=pos[1], pos[1]=pos[19], pos[19]=pos[46], pos[46]=pos[43], pos[43]=temp;
 temp=pos[4], pos[4]=pos[22], pos[22]=pos[49], pos[49]=pos[40], pos[40]=temp;
 temp=pos[7], pos[7]=pos[25], pos[25]=pos[52], pos[52]=pos[37], pos[37]=temp;
}

void Permutation::Equatorial()
{
 char temp;
 temp=pos[12], pos[12]=pos[39], pos[39]=pos[30], pos[30]=pos[21], pos[21]=temp;
 temp=pos[13], pos[13]=pos[40], pos[40]=pos[31], pos[31]=pos[22], pos[22]=temp;
 temp=pos[14], pos[14]=pos[41], pos[41]=pos[32], pos[32]=pos[23], pos[23]=temp;
}

void Permutation::EquatorialInverted()
{
 char temp;
 temp=pos[12], pos[12]=pos[21], pos[21]=pos[30], pos[30]=pos[39], pos[39]=temp;
 temp=pos[13], pos[13]=pos[22], pos[22]=pos[31], pos[31]=pos[40], pos[40]=temp;
 temp=pos[14], pos[14]=pos[23], pos[23]=pos[32], pos[32]=pos[41], pos[41]=temp;
}

void Permutation::Standing()
{
 char temp;
 temp=pos[3], pos[3]=pos[16], pos[16]=pos[50], pos[50]=pos[28], pos[28]=temp;
 temp=pos[4], pos[4]=pos[13], pos[13]=pos[49], pos[49]=pos[31], pos[31]=temp;
 temp=pos[5], pos[5]=pos[10], pos[10]=pos[48], pos[48]=pos[34], pos[34]=temp;
}

void Permutation::StandingInverted()
{
 char temp;
 temp=pos[3], pos[3]=pos[28], pos[28]=pos[50], pos[50]=pos[16], pos[16]=temp;
 temp=pos[4], pos[4]=pos[31], pos[31]=pos[49], pos[49]=pos[13], pos[13]=temp;
 temp=pos[5], pos[5]=pos[34], pos[34]=pos[48], pos[48]=pos[10], pos[10]=temp;
}

void Permutation::X()
{
 Right();
 MiddleInverted();
 LeftInverted();
}

void Permutation::XInverted()
{
 RightInverted();
 Middle();
 Left();
}

void Permutation::Y()
{
 Up();
 EquatorialInverted();
 DownInverted();
}

void Permutation::YInverted()
{
 UpInverted();
 Equatorial();
 Down(); 
}

void Permutation::Z()
{
 Front();
 Standing();
 BackInverted();
}

void Permutation::ZInverted()
{
 FrontInverted();
 StandingInverted();
 Back();
}

void Permutation::XRotate()
{
 char temp;
 char k;
 X();
 k=pos[4];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]='Z';
 temp=k;
 k=pos[22];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[49];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[40];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 for (int n=0; n<54; n++)
 if (pos[n]=='Z')
  pos[n]=temp;
}

void Permutation::XInvertedRotate()
{
 char temp;
 char k;
 XInverted();
 k=pos[4];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]='Z';
 temp=k;
 k=pos[40];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[49];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[22];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 for (int n=0; n<54; n++)
 if (pos[n]=='Z')
  pos[n]=temp;

}

void Permutation::YRotate()
{
 char temp;
 char k;
 Y();
 k=pos[13];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]='Z';
 temp=k;
 k=pos[22];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[31];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[40];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 for (int n=0; n<54; n++)
 if (pos[n]=='Z')
  pos[n]=temp;
}

void Permutation::YInvertedRotate()
{
 char temp;
 char k;
 YInverted();
 k=pos[13];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]='Z';
 temp=k;
 k=pos[40];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[31];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[22];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 for (int n=0; n<54; n++)
 if (pos[n]=='Z')
  pos[n]=temp;
}

void Permutation::ZRotate()
{
 char temp;
 char k;
 Z();
 k=pos[4];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]='Z';
 temp=k;
 k=pos[13];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[49];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[31];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 for (int n=0; n<54; n++)
 if (pos[n]=='Z')
  pos[n]=temp;
}

void Permutation::ZInvertedRotate()
{
 char temp;
 char k;
 ZInverted();
 k=pos[4];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]='Z';
 temp=k;
 k=pos[31];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[49];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 k=pos[13];
 for (int n=0; n<54; n++)
 if (pos[n]==k)
  pos[n]=temp;
 temp=k;
 for (int n=0; n<54; n++)
 if (pos[n]=='Z')
  pos[n]=temp;
}

void Permutation::set()
{
 for (int n=0; n<MaxMoves; n++)
  perm[n]='0';
 for (int n=0; n<=8; n++)
  pos[n]='W';
 for (int n=9; n<=17; n++)
  pos[n]='R';
 for (int n=18; n<=26; n++)
  pos[n]='B';
 for (int n=27; n<=35; n++)
  pos[n]='O';
 for (int n=36; n<=44; n++)
  pos[n]='G';
 for (int n=45; n<=53; n++)
  pos[n]='Y';
}

void Permutation::rotate(char arr[3])
{
 for (int s=0; s<3; s++)
 switch (arr[s])
 {
  case 'X':
  { 
   XRotate();
   break;
  }
  case 'Y':
  {
   YRotate();
   break;
  }
  case 'Z':
  {
   ZRotate();
   break;
  }
  case 'U':
  {
   XInvertedRotate();
   break;
  }
  case 'V':
  { 
   YInvertedRotate();
   break;
  }
  case 'W':
  {
   ZInvertedRotate();
   break;
  }
 }
}

void Permutation::print()
{
 for (int n=0; n<MaxMoves; n++)
  std::cout<<perm[n];
 for (int n=0; n<=53; n++)
  std::cout<<pos[n];
 std::cout<<std::endl;
}

void Permutation::save()
{
 std::ofstream fout;
 fout.open("perm.dat", std::ios::app);
 for (int n=0; n<MaxMoves; n++)
  fout<<perm[n];
 for (int n=0; n<=53; n++)
  fout<<pos[n];
 fout<<std::endl;
 fout.close();
}

int Permutation::check_mirror()
{
 char arr[21]={"00000000000000000000"};
 for (int n=0; n<20; n++)
  switch (perm[n])
  {
   case 'A':
   {
    arr[n]='B';
    break;
   }
   case 'B':
   {
    arr[n]='A';
    break;
   }
   case 'C':
   {
    arr[n]='D';
    break;
   }
   case 'D':
   {
    arr[n]='C';
    break;
   }
   case 'E':
   {
    arr[n]='H';
    break;
   }
   case 'F':
   {
    arr[n]='G';
    break;
   }
   case 'G':
   {
    arr[n]='F';
    break;
   }
   case 'H':
   {
    arr[n]='E';
    break;
   }
   case 'I':
   {
    arr[n]='J';
    break;
   }
   case 'J':
   {
    arr[n]='I';
    break;
   }
   case 'K':
   {
    arr[n]='L';
    break;
   }
   case 'L':
   {
    arr[n]='K';
    break;
   }
 }
 Permutation obj(arr);
 if (obj.check_repeat()==1 && obj.check_rotate()==1)
  return 1;
 else return 0;
}

int Permutation::check_rotate()
{
 char arr[4];
 for (int i=0; i<24; i++)
 {
  switch (i)
  {
   case 0:
   {
    strcpy(arr, "U00");
    break;
   }
   case 1:
   {
    strcpy(arr, "UZO");
    break;
   }
   case 2:
   {
    strcpy(arr, "UW0");
    break;
   }
   case 3:
   {
    strcpy(arr, "UZZ");
    break;
   }
   case 4:
   {
    strcpy(arr, "W00");
    break;
   }
   case 5:
   {
    strcpy(arr, "WZ0");
    break;
   }
   case 6:
   {
    strcpy(arr, "WW0");
    break;
   }
   case 7:
   {
    strcpy(arr, "WZZ");
    break;
   }
   case 8:
   {
    strcpy(arr, "000");
    break;
   }
   case 9:
   {
    strcpy(arr, "0Z0");
    break;
   }
   case 10:
   {
    strcpy(arr, "0W0");
    break;
   }
   case 11:
   {
    strcpy(arr, "0ZZ");
    break;
   }
   case 12:
   {
    strcpy(arr, "Y00");
    break;
   }
   case 13:
   {
    strcpy(arr, "YZ0");
    break;
   }
   case 14:
   {
    strcpy(arr, "YW0");
    break;
   }
   case 15:
   {
    strcpy(arr, "YZZ");
    break;
   }
   case 16:
   {
    strcpy(arr, "X00");
    break;
   }
   case 17:
   {
    strcpy(arr, "XZ0");
    break;
   }
   case 18:
   {
    strcpy(arr, "XW0");
    break;
   }
   case 19:
   {
    strcpy(arr, "XZZ");
    break;
   }
   case 20:
   {
    strcpy(arr, "XX0");
    break;
   }
   case 21:
   {
    strcpy(arr, "YY0");
    break;
   }
   case 22:
   {
    strcpy(arr, "XXZ");
    break;
   }
   case 23:
   {
    strcpy(arr, "XXW");
    break;
   }
  }
  Permutation obj(perm);
  obj.rotate(arr);
  if (obj.check_repeat()==0)
   return 0;
 }
 return 1;
}

int Permutation::check_repeat()
{
 char scramble[53];
 std::ifstream fin;
 std::string str[2];
 for(int n=0; n<=53; n++)
  str[0]+=pos[n];
 fin.open("perm.dat");
 while (!(fin.eof()))
 {
  fin.seekg(MaxMoves+1, std::ios::cur);
  fin.read(scramble, 54);
  str[1]=scramble;
  if(str[0].compare(str[1])==0)
  { 
   fin.close();
   return 0;
  }
 }
 fin.close();
 return 1;
}

void Permutation::check_and_save()
{
 Permutation obj(perm);
 if (obj.check_repeat()==1 && obj.check_rotate()==1 && obj.check_mirror()==1)
 {
  save();
  print();
 }
}
