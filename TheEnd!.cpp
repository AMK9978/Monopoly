#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
//BrightBlue>>0,Green>>1,Red>>2,Orange>>3,Purple>>4,Blue>>5,Yellow>>6,BrightGreen>>7,White>>8,Black>>9,Park>>10,Prison>>11,Tax>>12
int ansnumber = 0;
string ans;
int answer = 0;
int man;
int max = 0;
int k[3] = { -1,-1,-1 };
int l = 0;
int dice;
int mydice = 0;
int sum[5] = { 0,0,0,0,0 };
int money[5] = { 2000,2000,2000,2000,2000 };
int housecost[40] = { 0,60,0,60,0,0,100,0,100,120,0,140,0,140,160,0,180,180,0,200,0,220,0,220,240,0,260,0,260,280,100,300,300,0,320,0,0,350,0,400 };
int housecolor[40] = { 8,0,8,0,8,9,1,10,1,1,10,2,9,2,2,9,3,3,8,3,11,4,10,4,4,9,5,9,5,5,12,6,6,8,6,9,10,7,9,7 };
int houseowner[40] = { 0 };
bool househotel[40] = { 0 };
int housecostcolor[8] = { 0,0,0,0,0,0,0,0 };
int r[4] = { -1,-1,-1,-1 };
int bowner[5] = { 0,0,0,0,0 };
bool housestatus[40] = { 0 };
//int color[40] = {};
int m[8] = { 2,3,3,3,3,3,3,2 };
int hp[5][8] = { {0,0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 }, };
//d=documentg
int d[5];
int rp;
int revent;


int randomdice()
{
	srand(time(0));
	int dice = rand() % 6 + 1;
	return dice;
}
void randomplayer()
{
	for (int i = 0; i < 4; i++)
	{
		srand(time(0));
		r[i] = rand() % 4 + 1;
		if (r[i] == r[0] && i != 0 || r[i] == r[1] && i != 1 || r[2] == r[i] && 2 != i || r[3] == r[i] && 3 != i)
		{
			i--;
			continue;
		}
	}cout << "Players circle:" << endl;
	for (int i = 0; i < 4; i++)
	{

		cout << r[i] << "\t";
	}
	cout << endl;
}

void wait(int second)
{
	second *= 1000;
	Sleep(second);
}

void proccess(int i)
{
	if (sum[r[i]] == 20)
	{
		//prison
		if (d[r[i]] == 1)
		{
			//hichi
			d[r[i]] = 0;
			sum[r[i]] -= mydice;
			housestatus[sum[r[i]]] = 1;
		}
		else
		{
			cout << "Do you want to spend 200$ ?" << endl;
			cin >> ans;
			if (ans == "1")
			{
				money[r[i]] -= 200;
				sum[r[i]] -= mydice;
				housestatus[sum[r[i]]] = 1;
			}
			else
			{
				answer = 1;housestatus[sum[r[i]]] = 1;
			}
		}
	}
	else if (houseowner[sum[r[i]]] == r[i])
	{
		//owner is himself
	}
	else if (sum[r[i]] == 30)
	{
		//Tax
		money[r[i]] -= 100;
		housestatus[sum[r[i]]] = 1;
	}
	else if (sum[r[i]] == 7 || sum[r[i]] == 10 || sum[r[i]] == 22 || sum[r[i]] == 36)
	{
		housestatus[sum[r[i]]] = 1;
		cout << r[i] << "Player is in the PARK" << endl;
	}
	//White house
	else if (sum[r[i]] == 2 || sum[r[i]] == 4 || sum[r[i]] == 18 || sum[r[i]] == 33)
	{
		housestatus[sum[r[i]]] = 1;
		cout << r[i] << "Player is in the White house" << endl;
		srand(time(0));
		revent = rand() % 6 + 1;
		cout << revent << endl;
		if (revent == 1)
		{
			cout << r[i] << "Player , you lost 100$" << endl;
			money[r[i]] -= 100;

		}
		else if (revent == 2)
		{
			srand(time(0));

			do
			{
				rp = rand() % 3;
			} while (rp != r[i]);
			money[r[i]] -= 50;
			money[rp] += 50;
			cout << r[i] << "Player , you lost 50$" << endl;
			cout << rp << "Player , you get 50$" << endl;
		}
		else if (revent == 3)
		{
			cout << r[i] << "Player , you get 100$" << endl;
			money[r[i]] += 100;
		}
		else if (revent == 4)
		{
			srand(time(0));

			do
			{
				rp = rand() % 3;
			} while (rp != r[i]);
			money[r[i]] += 100;
			money[rp] -= 100;
			cout << r[i] << "Player , you get 100$" << endl;
			cout << rp << "Player , you lost 100$" << endl;
		}
		else if (revent == 5)
		{
			cout << r[i] << "Player , you are in Prison!" << endl;
			if (housestatus[20] == 0)
			{
				housestatus[sum[r[i]]] = 0;
				sum[r[i]] = 20;
				//prison
				if (d[r[i]] == 1)
				{
					//hichi
					d[r[i]] = 0;
					sum[r[i]] -= mydice;
					housestatus[sum[r[i]]] = 1;
				}
				else
				{
					cout << "Do you want to spend 200$ ?" << endl;
					cin >> ans;
					if (ans == "1")
					{
						money[r[i]] -= 200;
						sum[r[i]] -= mydice;
						housestatus[sum[r[i]]] = 1;
					}
					else
					{
						answer = 1;housestatus[sum[r[i]]] = 1;
					}
				}

			}
		}
		else if (revent == 6)
		{
			cout << r[i] << "Player , you get doc fpr Prison" << endl;
			if (d[r[i]] == 0)
			{
				d[r[i]] = 1;
			}
		}


	}
	//Black house
	else if (sum[r[i]] == 5 || sum[r[i]] == 12 || sum[r[i]] == 15 || sum[r[i]] == 25 || sum[r[i]] == 27 || sum[r[i]] == 35 || sum[r[i]] == 38)
	{
		housestatus[sum[r[i]]] = 1;
		if (houseowner[sum[r[i]]] == 0)
		{
			cout << r[i] << "Player , Do you want to buy this house?" << endl;
			cin >> ans;
			if (ans == "1")
			{
				money[r[i]] -= 200;
				bowner[r[i]]++;
				houseowner[sum[r[i]]] = r[i];
				hp[r[i]][housecolor[sum[r[i]]]]++;
			}
		}
		else if (houseowner[sum[r[i]]] != r[i])
		{

			money[r[i]] -= 50 * bowner[houseowner[sum[r[i]]]];
			money[houseowner[sum[r[i]]]] += 50 * bowner[houseowner[sum[r[i]]]];
		}
	}


	else
	{
		if (househotel[sum[r[i]]] == 0)
		{//without HOTEL

			if (houseowner[sum[r[i]]] == 0)
			{
				cout << r[i] << "Player,Do you want to buy it?" << endl;
				cin >> ans;
				if (ans == "1")
				{
					money[r[i]] -= housecost[sum[r[i]]];
					housecostcolor[housecolor[sum[r[i]]]] += housecost[sum[r[i]]];
					housestatus[sum[r[i]]] = 1;
					hp[r[i]][housecolor[sum[r[i]]]]--;
					cout << r[i] << "Player is in the" << sum[r[i]] << " House" << endl;
					cout << r[i] << "Player bought this house" << endl;
					//Does he can builds HOTEL?
					if (hp[r[i]][housecolor[sum[r[i]]]]==m[housecolor[sum[r[i]]]])
					{
						cout << "Do you want to bulid houtel on this house?" << endl;
						cin >> ans;
						if (ans == "1")
						{
							money[r[i]] -= housecostcolor[housecolor[sum[r[i]]]];
							househotel[sum[r[i]]] = 1;
							cout << r[i] << "Player , built Hotel" << endl;

						}
					}
				}
				else
				{

					for (int k = 0; k < 4; k++)
					{
						cout << r[k] << "Player sugesstion: ";
						cin >> ansnumber;
						if (ansnumber>max)
						{
							max = ansnumber;
							man = r[k];
						}
					}
					if (r[i] == man)
					{
						money[man] -= max;
						housestatus[sum[r[i]]] = 1;
						houseowner[sum[r[i]]] = r[i];
						cout << r[i] << "Player , is owner of " << sum[r[i]] << "house" << endl;
						hp[r[i]][housecolor[sum[r[i]]]]++;
						if (hp[r[i]][housecolor[sum[r[i]]]] == m[housecolor[sum[r[i]]]])
						{
							cout << man << " wants to bulid houtel on this house?" << endl;
							cin >> ans;
							if (ans == "1")
							{
								money[man] -= housecostcolor[sum[r[i]]];
								househotel[sum[r[i]]] = 1;

							}
						}

					}
					else
					{
						cout << man << "Player , is owner of " << sum[r[i]] << "house" << endl;
						houseowner[sum[r[i]]] = man;
						money[man] -= max;
						houseowner[sum[r[i]]] = man;
						housestatus[sum[r[i]]] = 1;
						money[r[i]] -= housecost[sum[r[i]]] / 2;
						money[man] += housecost[sum[r[i]]] / 2;
					}
				}
			}
			else
			{
				money[r[i]] -= housecost[sum[r[i]]] / 2;
				money[houseowner[sum[r[i]]]] += housecost[sum[r[i]]] / 2;
				housestatus[sum[r[i]]] = 1;
			}

		}
		else
		{
			money[r[i]] -= housecostcolor[housecolor[sum[r[i]]]] / 2;
			money[houseowner[sum[r[i]]]] += housecostcolor[housecolor[sum[r[i]]]] / 2;
			housestatus[sum[r[i]]] = 1;

		}

	}

}

void survive(int i)
{
	int j = 1;
	while (money[r[i]] <= 0 && househotel[j] == 1 && houseowner[j] == r[i] && housestatus[j] == 0)
	{
		cout << "Do you want to give its Hotel up?" << endl;
		if (ans == "1")
		{
			hp[r[i]][housecolor[sum[r[i]]]]--;
			money[r[i]] += housecostcolor[housecolor[j]];
			househotel[j] = 0;
		}
		else
		{
			if (j == 39)
			{
				j = 0;
			}
		}
		j++;
	}
	j = 1;
	while (money[r[i]] <= 0 && househotel[j] == 0 && houseowner[j] == r[i] && housestatus[j] == 0)
	{
		cout << "Do you want to give it up?" << endl;
		if (ans == "1")
		{
			houseowner[j] = 0;
			housecostcolor[housecolor[j]] -= housecost[j];
			money[r[i]] += housecost[j];

		}
		else
		{
			if (j == 39)
			{
				j = 0;
			}
		}
		j++;
	}
	if (money[r[i]] <= 0)
	{
		cout << r[i] << "Player has lost!" << endl;
		k[l] = r[i];
		l++;
	}
	if (l == 2)
	{
		cout << k[0] << "," << k[1] << "," << k[2] << ",Players have lost!" << endl;

	}

}
void start()
{
	/*//HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	font.nFont = 0;
	//GetCurrentConsoleFontEx(outcon, false, &font);
	font.dwFontSize.X = 0;
	font.dwFontSize.Y =24;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;
//	std::wcscpy(font.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,&font);
	cout << "    start"<< endl;

	//SetCurrentConsoleFontEx(outcon, false, &font);
	//	cout << " \n\n\n               start" SetConsoleTextAttribute(outcon, 0x0C);
	
	*/
	cout << "\n\n\n\tA";wait(1);cout << "m";wait(1);cout << "i";wait(1);cout << "r";wait(1);cout << "mohammad Karimi ";wait(1);cout << "and ";wait(1);cout << "A";wait(1);cout << "l";wait(1);cout << "i";wait(1);cout << " Bahreiniyan" << endl;
	wait(2);
	cout << "\n\n\t\t\tPRESENT:" << endl;
	wait(2);
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t   ALL Rights Reserved!" << endl;
	wait(4);
	system("cls");
	int n = 0;
	while (n < 3) {
		cout << endl << endl << endl << endl;
		system("color 1E");
		cout << "\t$$$$$$$$$$ ##########    *         ********* $$$$$$$$$$$           \n";
		cout << "\t$              #        * *        *       *      $                \n";
		cout << "\t$              #       *   *       *       *      $                 \n";
		cout << "\t$              #      *******      *       *      $                 \n";
		cout << "\t$$$$$$$$$$     #     *       *     *********      $                 \n";
		cout << "\t         $     #    *         *    *        $     $                \n";
		cout << "\t         $     #   *           *   *         $    $                 \n";
		cout << "\t         $     #  *             *  *          $   $                \n";
		cout << "\t$$$$$$$$$$     # *               * *           $  $                 \n";
		cout << endl << endl;
		wait(1);
		system("color 3");
		wait(1);
		system("color 07");
		wait(1);
		n++;system("cls");
	}

	
}
void change(int i) {
	if (i%2==0)
	{
		system("color F0");
	}
	else
	{
		system("color 70");
	}
}
void board(int i)
{
	int a[11][11];
	if (true)
	{

	}
	
}
int main()
{/*
	WORD color;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	color = (csbi.wAttributes & 0xF0);
	SetConsoleTextAttribute(h, color);
	cout << "salam" << endl;
	for (int n = 0; n < 40; n++)
	{
		housestatus[n] = 0;houseowner[n] = 0;househotel[n] = 0;
	}*/

	 //start();
	wait(1);
	start();
	randomplayer();
	//int i = 0;
	//Nobat
	for (int i = 0;i<4;i++)
	{
		wait(1);
		system("cls");
		change(i);
		cout << r[i] << "Player " << endl << endl;
		mydice = randomdice();
		cout << endl << "Dice is: " << mydice << endl;
		cout << "\a\a";
		wait(1);
		housestatus[sum[r[i]]] = 0;
		sum[r[i]] += mydice;
		if (sum[r[i]] >= 40)
		{
			sum[r[i]] -= 40;
		}
		if (housestatus[sum[r[i]]] == 1)
		{
			cout << "This Houes has been occupationed" << endl;
			sum[r[i]] -= mydice;
			i--;
			continue;
		}
		cout << endl << "\t" << sum[r[i]] << endl;
		survive(i);
		if (answer == 1)
		{
			answer = 0;
			continue;
		}
		if (r[i] == k[0] || r[i] == k[1])
		{
			continue;
		}
		proccess(i);
		if (l == 2)
		{
			cout << "FiniSh" << endl;
			break;
		}
		if (i == 3)
		{
			i = -1;
			continue;
		}
	}

	int weq;cin >> weq;
}