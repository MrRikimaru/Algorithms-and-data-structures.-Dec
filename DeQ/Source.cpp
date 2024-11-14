#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

class double_ended_queue
{
	class headphone
	{
	private:
		string company;
		string model;
		int interf;
		int cost;
	public:
		void setCompany(string value)
		{
			company = value;
		}
		string getCompany()
		{
			return company;
		}
		void setModel(string value)
		{
			model = value;
		}
		string getModel()
		{
			return model;
		}
		void setInterf(int value)
		{
			interf = value;
		}
		int getInterf()
		{
			return interf;
		}
		void setCost(int value)
		{
			cost = value;
		}
		int getCost()
		{
			return cost;
		}
	};
private:
	int deq_size = 0, value = 0;
	void push_head(headphone*& HP, int& deq_size, headphone*& hp_value)
	{
		if (deq_size == 0)
		{
			headphone* buffer = new headphone[deq_size + 1];
			buffer[0].setCompany(hp_value[0].getCompany());
			buffer[0].setModel(hp_value[0].getModel());
			buffer[0].setInterf(hp_value[0].getInterf());
			buffer[0].setCost(hp_value[0].getCost());
			delete[] HP;
			HP = buffer;
			deq_size++;
		}
		else
		{
			headphone* buffer = new headphone[deq_size + 1];
			for (int i = 0; i < deq_size; i++)
			{
				buffer[i + 1].setCompany(HP[i].getCompany());
				buffer[i + 1].setModel(HP[i].getModel());
				buffer[i + 1].setInterf(HP[i].getInterf());
				buffer[i + 1].setCost(HP[i].getCost());
			}
			buffer[0].setCompany(hp_value[0].getCompany());
			buffer[0].setModel(hp_value[0].getModel());
			buffer[0].setInterf(hp_value[0].getInterf());
			buffer[0].setCost(hp_value[0].getCost());
			delete[] HP;
			HP = buffer;
			deq_size++;
		}
	}
	void push_tail(headphone*& HP, int& deq_size, headphone*& hp_value)
	{
		if (deq_size == 0)
		{
			headphone* buffer = new headphone[deq_size + 1];
			buffer[0].setCompany(hp_value[0].getCompany());
			buffer[0].setModel(hp_value[0].getModel());
			buffer[0].setInterf(hp_value[0].getInterf());
			buffer[0].setCost(hp_value[0].getCost());
			delete[] HP;
			HP = buffer;
			deq_size++;
		}
		else
		{
			headphone* buffer = new headphone[deq_size + 1];
			for (int i = 0; i < deq_size; i++)
			{
				buffer[i].setCompany(HP[i].getCompany());
				buffer[i].setModel(HP[i].getModel());
				buffer[i].setInterf(HP[i].getInterf());
				buffer[i].setCost(HP[i].getCost());
			}
			buffer[deq_size].setCompany(hp_value[0].getCompany());
			buffer[deq_size].setModel(hp_value[0].getModel());
			buffer[deq_size].setInterf(hp_value[0].getInterf());
			buffer[deq_size].setCost(hp_value[0].getCost());
			deq_size++;
			delete[] HP;
			HP = buffer;
		}
	}
	void pop_head(headphone*& HP, int& deq_size)
	{
		if (deq_size == 0)
		{
			cout << endl << endl << "Невозможно извлечь элемент! Дек пуст!" << endl;
			system("pause");
		}
		else if(deq_size == 1)
		{
			clear_deq(HP, deq_size);
		}
		else
		{
			headphone* buffer = new headphone[deq_size - 1];
			for (int i = 0; i < deq_size - 1; i++)
			{
				buffer[i].setCompany(HP[i + 1].getCompany());
				buffer[i].setModel(HP[i + 1].getModel());
				buffer[i].setInterf(HP[i + 1].getInterf());
				buffer[i].setCost(HP[i + 1].getCost());
			}
			deq_size--;
			delete[] HP;
			HP = buffer;
		}
	}
	void pop_tail(headphone*& HP, int& deq_size)
	{
		if (deq_size == 0)
		{
			cout << endl << endl << "Невозможно извлечь элемент! Дек пуст!" << endl;
			system("pause");
		}
		else if (deq_size == 1)
		{
			clear_deq(HP, deq_size);
		}
		else
		{
			headphone* buffer = new headphone[deq_size - 1];
			for (int i = 0; i < deq_size - 1; i++)
			{
				buffer[i].setCompany(HP[i].getCompany());
				buffer[i].setModel(HP[i].getModel());
				buffer[i].setInterf(HP[i].getInterf());
				buffer[i].setCost(HP[i].getCost());
			}
			deq_size--;
			delete[] HP;
			HP = buffer;
		}
	}
	void clear_deq(headphone*& HP, int& deq_size)
	{
		delete[] HP;
		deq_size = 0;
	}
	void check_deq(int& deq_size)
	{
		if (deq_size == 0)
		{
			cout << endl << endl << "Дек пуст!" << endl;
		}
		else
			cout << endl << endl << "Дек не пуст!" << endl;
	}
	void print_deq_table_format(headphone*& HP, int& deq_size)
	{
		int counter = 0;
		int* Max = new int[5]{ 7, 15, 8, 12, 6 };
		string* Name = new string[5]{ "[НОМЕР]" , "[ПРОИЗВОДИТЕЛЬ]" , "[МОДЕЛЬ]", "[ИНТЕРФЕЙС]", "[ЦЕНА]" };
		for (int i = 0; i < deq_size; i++)
		{
			if (strlen(to_string(i).c_str()) > Max[0])
			{
				Max[0] = strlen(to_string(i).c_str());
			}
			if (strlen(HP[i].getCompany().c_str()) > Max[1])
			{
				Max[1] = strlen(HP[i].getCompany().c_str());
			}
			if (strlen(HP[i].getModel().c_str()) > Max[2])
			{
				Max[2] = strlen(HP[i].getModel().c_str());
			}
			if (strlen(to_string(HP[i].getCost()).c_str()) > Max[4])
			{
				Max[4] = strlen(to_string(HP[i].getCost()).c_str());
			}
		}
		for (int i = 0; i < 5; i++)
		{
			SetConsoleOutputCP(866);
			if (i == 0)
			{
				cout << char(201);
			}
			for (int j = 0; j <= Max[i] + 1; j++)
			{
				cout << char(205);
				if ((i == 4) && (j == Max[i] + 1))
				{
					cout << char(187);
				}
				else if (j == Max[i] + 1)
				{
					cout << char(203);
				}
			}
			SetConsoleOutputCP(1251);
		}
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			SetConsoleOutputCP(866);
			cout << (char)186 << " ";
			SetConsoleOutputCP(1251);
			cout << Name[i] << " ";
			if (strlen(Name[i].c_str()) <= Max[i])
			{
				for (int j = 0; j < Max[i] - strlen(Name[i].c_str()); j++)
				{
					cout << " ";
				}
				if (i == 4)
				{
					SetConsoleOutputCP(866);
					cout << (char)186;
					SetConsoleOutputCP(1251);
				}
			}
		}
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			SetConsoleOutputCP(866);
			if (i == 0)
			{
				cout << char(204);
			}
			for (int j = 0; j <= Max[i] + 1; j++)
			{
				cout << char(205);
				if ((i == 4) && (j == Max[i] + 1))
				{
					cout << char(185);
				}
				else if (j == Max[i] + 1)
				{
					cout << char(206);
				}
			}
			SetConsoleOutputCP(1251);
		}
		cout << endl;
		for (int i = 0; i < deq_size; i++)
		{
			SetConsoleOutputCP(866);
			cout << (char)186 << " ";
			SetConsoleOutputCP(1251);
			cout << i;
			if (strlen(to_string(i).c_str()) == Max[0])
			{
				SetConsoleOutputCP(866);
				cout << " " << char(186) << " ";
				SetConsoleOutputCP(1251);
			}
			if (strlen(to_string(i).c_str()) < Max[0])
			{
				SetConsoleOutputCP(866);
				for (int j = 0; j < Max[0] - strlen(to_string(i).c_str()); j++)
				{
					cout << " ";
					if (j == (Max[0] - strlen(to_string(i).c_str()) - 1))
					{
						cout << " " << char(186) << " ";
					}
				}
				SetConsoleOutputCP(1251);
			}
			cout << HP[i].getCompany();
			if (strlen(HP[i].getCompany().c_str()) == Max[1])
			{
				SetConsoleOutputCP(866);
				cout << " " << char(186) << " ";
				SetConsoleOutputCP(1251);
			}
			if (strlen(HP[i].getCompany().c_str()) < Max[1])
			{
				SetConsoleOutputCP(866);
				for (int j = 0; j < Max[1] - strlen(HP[i].getCompany().c_str()); j++)
				{
					cout << " ";
					if (j == (Max[1] - strlen(HP[i].getCompany().c_str())) - 1)
					{
						cout << " " << char(186) << " ";
					}
				}
				SetConsoleOutputCP(1251);
			}
			cout << HP[i].getModel();
			if (strlen(HP[i].getModel().c_str()) == Max[2])
			{
				SetConsoleOutputCP(866);
				cout << " " << char(186) << " ";
				SetConsoleOutputCP(1251);
			}
			if (strlen(HP[i].getModel().c_str()) < Max[2])
			{
				SetConsoleOutputCP(866);
				for (int j = 0; j < Max[2] - strlen(HP[i].getModel().c_str()); j++)
				{
					cout << " ";
					if (j == (Max[2] - strlen(HP[i].getModel().c_str())) - 1)
					{
						cout << " " << char(186) << " ";
					}
				}
				SetConsoleOutputCP(1251);
			}
			if (HP[i].getInterf() == 0)
			{
				cout << "Беспроводные";
				SetConsoleOutputCP(866);
				cout << " " << char(186) << " ";
				SetConsoleOutputCP(1251);
			}
			else
			{
				cout << "Проводные";
				SetConsoleOutputCP(866);
				for (int j = 0; j < Max[3] - 9; j++)
				{
					cout << " ";
					if (j == (Max[3] - 10))
					{
						cout << " " << char(186) << " ";
					}
				}
				SetConsoleOutputCP(1251);
			}
			cout << HP[i].getCost();
			if (strlen(to_string(HP[i].getCost()).c_str()) == Max[4])
			{
				SetConsoleOutputCP(866);
				cout << " " << char(186) << " ";
				SetConsoleOutputCP(1251);
			}
			if (strlen(to_string(HP[i].getCost()).c_str()) < Max[4])
			{
				SetConsoleOutputCP(866);
				for (int j = 0; j < Max[4] - strlen(to_string(HP[i].getCost()).c_str()); j++)
				{
					cout << " ";
					if (j == (Max[4] - strlen(to_string(HP[i].getCost()).c_str()) - 1))
					{
						cout << " " << char(186) << " ";
					}
				}
				SetConsoleOutputCP(1251);
			}
			cout << endl;
			if (i == deq_size - 1)
			{
				for (int i = 0; i < 5; i++)
				{
					SetConsoleOutputCP(866);
					if (i == 0)
					{
						cout << char(200);
					}
					for (int j = 0; j <= Max[i] + 1; j++)
					{
						cout << char(205);
						if ((i == 4) && (j == Max[i] + 1))
						{
							cout << char(188);
						}
						else if (j == Max[i] + 1)
						{
							cout << char(202);
						}
					}
					SetConsoleOutputCP(1251);
				}
				cout << endl;
			}
			else
			{
				for (int i = 0; i < 5; i++)
				{
					SetConsoleOutputCP(866);
					if (i == 0)
					{
						cout << char(204);
					}
					for (int j = 0; j <= Max[i] + 1; j++)
					{
						cout << char(205);
						if ((i == 4) && (j == Max[i] + 1))
						{
							cout << char(185);
						}
						else if (j == Max[i] + 1)
						{
							cout << char(206);
						}
					}
					SetConsoleOutputCP(1251);
				}
				cout << endl;
			}
		}
	}
	void deq_sort(headphone*& HP, int& deq_size)
	{
		bool menu = 1, sub_menu = 1;
		while (menu)
		{
			sub_menu = 1;
			headphone* hp_buff = new headphone[1];
			int counter = 0;
			cout << "Сортировка записей в деке:" << endl;
			cout << "0. Сортировать по производителю." << endl;
			cout << "1. Сортировать по модели." << endl;
			cout << "2. Сортировать по интерфейсу." << endl;
			cout << "3. Сортировать по цене." << endl;
			if (!_kbhit())
			{
				while (sub_menu)
				{
					switch (_getch())
					{
					case 27:
					{
						system("cls");
						menu = sub_menu = false;
						break;
					}
					case '0':
					{
						system("cls");
						if (deq_size == 0)
						{
							cout << "Дек пуст. Сортировка невозможна." << endl;
							system("pause");
							menu = sub_menu = 0;
							break;
						}
						else if (deq_size == 1)
						{
							cout << "Дек содержит 1 запись. Сортировка невозможна." << endl;
							system("pause");
							menu = sub_menu = 0;
							break;
						}
						else if (deq_size > 1)
						{
							for (int i = 0; i < deq_size; i++)
							{
								for (int j = deq_size - 1; j >= (i + 1); j--)
								{
									counter = 0;
									if (HP[j].getCompany() == HP[j - 1].getCompany())
									{
										continue;
									}
									if (HP[j].getCompany()[counter] == HP[j - 1].getCompany()[counter])
									{
										while (HP[j].getCompany()[counter] == HP[j - 1].getCompany()[counter])
										{
											if ((counter <= strlen(HP[j].getCompany().c_str()) - 1) && (counter <= strlen(HP[j - 1].getCompany().c_str()) - 1))
											{
												counter++;
											}
											else
												break;
										}
										if ((HP[j].getCompany()[counter] == HP[j - 1].getCompany()[counter]) && ((counter == strlen(HP[j].getCompany().c_str()) || counter == strlen(HP[j - 1].getCompany().c_str()))))
										{
											if (counter == strlen(HP[j - 1].getCompany().c_str()))
											{
												hp_buff[0].setCompany(HP[j].getCompany());
												hp_buff[0].setModel(HP[j].getModel());
												hp_buff[0].setInterf(HP[j].getInterf());
												hp_buff[0].setCost(HP[j].getCost());
												HP[j].setCompany(HP[j - 1].getCompany());
												HP[j].setModel(HP[j - 1].getModel());
												HP[j].setInterf(HP[j - 1].getInterf());
												HP[j].setCost(HP[j - 1].getCost());
												HP[j - 1].setCompany(hp_buff[0].getCompany());
												HP[j - 1].setModel(hp_buff[0].getModel());
												HP[j - 1].setInterf(hp_buff[0].getInterf());
												HP[j - 1].setCost(hp_buff[0].getCost());
											}
											else
											{
												continue;
											}
										}
									}
									if (HP[j].getCompany()[counter] < HP[j - 1].getCompany()[counter])
									{
										hp_buff[0].setCompany(HP[j].getCompany());
										hp_buff[0].setModel(HP[j].getModel());
										hp_buff[0].setInterf(HP[j].getInterf());
										hp_buff[0].setCost(HP[j].getCost());
										HP[j].setCompany(HP[j - 1].getCompany());
										HP[j].setModel(HP[j - 1].getModel());
										HP[j].setInterf(HP[j - 1].getInterf());
										HP[j].setCost(HP[j - 1].getCost());
										HP[j - 1].setCompany(hp_buff[0].getCompany());
										HP[j - 1].setModel(hp_buff[0].getModel());
										HP[j - 1].setInterf(hp_buff[0].getInterf());
										HP[j - 1].setCost(hp_buff[0].getCost());
									}
								}
							}
						}
						cout << "Сортировка завершена." << endl;
						system("pause");
						menu = sub_menu = 0;
						break;
					}
					case '1':
					{
						system("cls");
						if (deq_size == 0)
						{
							cout << "Дек пуст. Сортировка невозможна." << endl;
							system("pause");
							menu = sub_menu = 0;
							break;
						}
						else if (deq_size == 1)
						{
							cout << "Дек содержит 1 запись. Сортировка невозможна." << endl;
							system("pause");
							menu = sub_menu = 0;
							break;
						}
						else if (deq_size > 1)
						{
							for (int i = 0; i < deq_size; i++)
							{
								for (int j = deq_size - 1; j >= (i + 1); j--)
								{
									counter = 0;
									if (HP[j].getModel() == HP[j - 1].getModel())
									{
										continue;
									}
									if (HP[j].getModel()[counter] == HP[j - 1].getModel()[counter])
									{
										while (HP[j].getModel()[counter] == HP[j - 1].getModel()[counter])
										{
											if ((counter <= strlen(HP[j].getModel().c_str()) - 1) && (counter <= strlen(HP[j - 1].getModel().c_str()) - 1))
											{
												counter++;
											}
											else
												break;
										}
										if ((HP[j].getModel()[counter] == HP[j - 1].getModel()[counter]) && ((counter == strlen(HP[j].getModel().c_str()) || counter == strlen(HP[j - 1].getModel().c_str()))))
										{
											if (counter == strlen(HP[j - 1].getModel().c_str()))
											{
												hp_buff[0].setCompany(HP[j].getCompany());
												hp_buff[0].setModel(HP[j].getModel());
												hp_buff[0].setInterf(HP[j].getInterf());
												hp_buff[0].setCost(HP[j].getCost());
												HP[j].setCompany(HP[j - 1].getCompany());
												HP[j].setModel(HP[j - 1].getModel());
												HP[j].setInterf(HP[j - 1].getInterf());
												HP[j].setCost(HP[j - 1].getCost());
												HP[j - 1].setCompany(hp_buff[0].getCompany());
												HP[j - 1].setModel(hp_buff[0].getModel());
												HP[j - 1].setInterf(hp_buff[0].getInterf());
												HP[j - 1].setCost(hp_buff[0].getCost());
											}
											else
											{
												continue;
											}
										}
									}
									if (HP[j].getModel()[counter] < HP[j - 1].getModel()[counter])
									{
										hp_buff[0].setCompany(HP[j].getCompany());
										hp_buff[0].setModel(HP[j].getModel());
										hp_buff[0].setInterf(HP[j].getInterf());
										hp_buff[0].setCost(HP[j].getCost());
										HP[j].setCompany(HP[j - 1].getCompany());
										HP[j].setModel(HP[j - 1].getModel());
										HP[j].setInterf(HP[j - 1].getInterf());
										HP[j].setCost(HP[j - 1].getCost());
										HP[j - 1].setCompany(hp_buff[0].getCompany());
										HP[j - 1].setModel(hp_buff[0].getModel());
										HP[j - 1].setInterf(hp_buff[0].getInterf());
										HP[j - 1].setCost(hp_buff[0].getCost());
									}
								}
							}
						}
						menu = sub_menu = 0;
						cout << "Сортировка завершена." << endl;
						system("pause");
						break;
					}
					case '2':
					{
						system("cls");
						if (deq_size == 0)
						{
							cout << "Дек пуст. Сортировка невозможна." << endl;
							system("pause");
							menu = sub_menu = 0;
							break;
						}
						else if (deq_size == 1)
						{
							cout << "Дек содержит 1 запись. Сортировка невозможна." << endl;
							system("pause");
							menu = sub_menu = 0;
							break;
						}
						else if (deq_size > 2)
						{
							for (int i = 0; i < deq_size; i++)
							{
								for (int j = (deq_size - 1); j >= (i + 1); j--)
								{
									if (HP[j].getInterf() < HP[j - 1].getInterf())
									{
										hp_buff[0].setCompany(HP[j].getCompany());
										hp_buff[0].setModel(HP[j].getModel());
										hp_buff[0].setInterf(HP[j].getInterf());
										hp_buff[0].setCost(HP[j].getCost());
										HP[j].setCompany(HP[j - 1].getCompany());
										HP[j].setModel(HP[j - 1].getModel());
										HP[j].setInterf(HP[j - 1].getInterf());
										HP[j].setCost(HP[j - 1].getCost());
										HP[j - 1].setCompany(hp_buff[0].getCompany());
										HP[j - 1].setModel(hp_buff[0].getModel());
										HP[j - 1].setInterf(hp_buff[0].getInterf());
										HP[j - 1].setCost(hp_buff[0].getCost());
									}
								}
							}
						}
						cout << "Сортировка завершена." << endl;
						system("pause");
						menu = sub_menu = 0;
						break;
					}
					case '3':
					{
						system("cls");
						if (deq_size == 0)
						{
							cout << "Дек пуст. Сортировка невозможна." << endl;
							system("pause");
							menu = sub_menu = 0;
							break;
						}
						else if (deq_size == 1)
						{
							cout << "Дек содержит 1 запись. Сортировка невозможна." << endl;
							system("pause");
							menu = sub_menu = 0;
							break;
						}
						else if (deq_size > 2)
						{
							for (int i = 0; i < deq_size; i++)
							{
								for (int j = (deq_size - 1); j >= (i + 1); j--)
								{
									if (HP[j].getCost() < HP[j - 1].getCost())
									{
										hp_buff[0].setCompany(HP[j].getCompany());
										hp_buff[0].setModel(HP[j].getModel());
										hp_buff[0].setInterf(HP[j].getInterf());
										hp_buff[0].setCost(HP[j].getCost());
										HP[j].setCompany(HP[j - 1].getCompany());
										HP[j].setModel(HP[j - 1].getModel());
										HP[j].setInterf(HP[j - 1].getInterf());
										HP[j].setCost(HP[j - 1].getCost());
										HP[j - 1].setCompany(hp_buff[0].getCompany());
										HP[j - 1].setModel(hp_buff[0].getModel());
										HP[j - 1].setInterf(hp_buff[0].getInterf());
										HP[j - 1].setCost(hp_buff[0].getCost());
									}
								}
							}
						}
						cout << "Сортировка завершена." << endl;
						system("pause");
						menu = sub_menu = 0;
						break;
					}
					default:
					{
						break;
					}
					}
				}
			}

			delete[] hp_buff;
		}
	}
	void edit_deq(headphone*& HP, int& deq_size)
	{
		int value = 0, buff_i = 0;
		string buff_s = "";
		bool menu = 1, sub_menu = 1, check = 1;
		cout << endl;
		cout << "Введите номер записи, в которую хотите внести изменение:";
		cin >> value;
		if ((value < 0)||(value > deq_size-1))
		{
			cout << "Ошибка. Введеное неверное значение!" << endl;
			system("pause");
		}
		else
		{
			sub_menu = 1;
			cout << endl << "0. Измененить данные производителя." << endl;
			cout << "1. Изменить данные модели." << endl;
			cout << "2. Изменить интерфейс." << endl;
			cout << "3. Изменить цену." << endl;
			if (!_kbhit())
			{
				while (menu)
				{
					switch (_getch())
					{
					case 27:
					{
						menu = 0;
						break;
					}
					case '0':
					{
						cout << endl << "Введите производителя:";
						cin >> buff_s;
						HP[value].setCompany(buff_s);
						menu = 0;
						break;
					}
					case '1':
					{
						cout << endl << "Введите модель:";
						cin >> buff_s;
						HP[value].setModel(buff_s);
						menu = 0;
						break;
					}
					case '2':
					{
						bool correct = 0, corr_menu = 0;
						while (!correct)
						{
							corr_menu = 1;
							if (!_kbhit())
							{
								while (corr_menu)
								{
									cout << "Выбирите интерфейс [0 - Беспроводной, 1 - Проводной] :";
									switch (_getch())
									{
									case '0':
									{
										HP[value].setInterf(0);
										cout << "Беспроводной." << endl;
										correct = 1;
										corr_menu = 0;
										break;
									}
									case '1':
									{
										HP[value].setInterf(1);
										cout << "Проводной." << endl;
										correct = 1;
										corr_menu = 0;
										break;
									}
									default:
									{
										cout << "Ошибка. Неверное значение!" << endl;
										break;
										corr_menu = 0;
									}
									}
								}
							}
						}
						menu = 0;
						break;
					}
					case '3':
					{
						cout << endl << "Введите цену:";
						cin >> buff_i;
						HP[value].setCost(buff_i);
						menu = 0;
						break;
					}
					default:
					{
						break;
					}
					}
				}
			}
		}
	}
public:
	void set_deq()
	{
		string buff_s = "";
		int buff_i = 0;
		bool menu = 1, sub_menu = 1;
		headphone* HP = new headphone[deq_size];
		while (menu)
		{
			sub_menu = 1;
			system("cls");
			cout << "ГЛАВНОЕ МЕНЮ:" << endl;
			cout << "0. Дек" << endl;
			cout << "1. Действия с записями дека." << endl;
			if (!_kbhit())
			{
				while (sub_menu)
				{
					switch (_getch())
					{
					case 27:
					{
						menu = sub_menu = 0;
						break;
					}
					case '0':
					{
						bool menu_0 = 1, sub_menu_0 = 1;
						while (menu_0)
						{
							sub_menu_0 = 1;
							system("cls");
							cout << "ДЕК:" << endl;
							cout << "0. Добавить элемент в начало." << endl;
							cout << "1. Добавить элемент в конец." << endl;
							cout << "2. Извлечь элемент из начала." << endl;
							cout << "3. Извлечь элемент из конца." << endl;
							cout << "4. Очистить дек" << endl;
							cout << "5. Проверка пустоты дека." << endl;
							if (!_kbhit())
							{
								while (sub_menu_0)
								{
									switch (_getch())
									{
									case 27:
									{
										menu_0 = sub_menu_0 = sub_menu = 0;
										break;
									}
									case '0':
									{
										headphone* hp_value = new headphone[1];
										bool check = 1, check_1 = 1,correct = 1;
										cout << endl << endl << "Введите компанию производитель:";
										cin >> buff_s;
										hp_value[0].setCompany(buff_s);
										cout << "Введите модель:";
										cin >> buff_s;
										hp_value[0].setModel(buff_s);
										while (check)
										{
											if (!_kbhit())
											{
												while (check_1)
												{
													cout << "Выбирите интерфейс [0 - Беспроводной, 1 - Проводной] :";
													switch (_getch())
													{
													case '0':
													{
														hp_value[0].setInterf(0);
														cout << "Беспроводной." << endl;
														check = check_1 = 0;
														break;
													}
													case '1':
													{
														hp_value[0].setInterf(1);
														cout << "Проводной." << endl;
														check = check_1 = 0;
														break;
													}
													default:
													{
														cout << "Ошибка. Неверное значение!" << endl;
														break;
													}
													}
												}
											}
										}
										check = 1;
										while (check)
										{
											cout << "Введите цену:";
											cin >> buff_s;
											for (int i = 0; i < strlen(buff_s.c_str()); i++)
											{
												if ((buff_s[i] < '0') || (buff_s[i] > '9'))
												{
													cout << "Ошибка. Введено неверное значение!" << endl;
													correct = 0;
													break;
												}
												else
													correct = 1;
											}
											if (correct == 1)
											{
												hp_value[0].setCost(atoi(buff_s.c_str()));
												check = 0;
											}
										}
										push_head(HP, deq_size, hp_value);
										delete[] hp_value;
										sub_menu_0 = 0;
										break;
									}
									case '1':
									{
										headphone* hp_value = new headphone[1];
										bool check = 1, check_1 = 1, correct = 1;
										cout << endl << endl << "Введите компанию производитель:";
										cin >> buff_s;
										hp_value[0].setCompany(buff_s);
										cout << "Введите модель:";
										cin >> buff_s;
										hp_value[0].setModel(buff_s);
										while (check)
										{
											if (!_kbhit())
											{
												while (check_1)
												{
													cout << "Выбирите интерфейс [0 - Беспроводной, 1 - Проводной] :";
													switch (_getch())
													{
													case '0':
													{
														hp_value[0].setInterf(0);
														cout << "Беспроводной." << endl;
														check = check_1 = 0;
														break;
													}
													case '1':
													{
														hp_value[0].setInterf(1);
														cout << "Проводной." << endl;
														check = check_1 = 0;
														break;
													}
													default:
													{
														cout << "Ошибка. Неверное значение!" << endl;
														break;
													}
													}
												}
											}
										}
										check = 1;
										while (check)
										{
											cout << "Введите цену:";
											cin >> buff_s;
											for (int i = 0; i < strlen(buff_s.c_str()); i++)
											{
												if ((buff_s[i] < '0') || (buff_s[i] > '9'))
												{
													cout << "Ошибка. Введено неверное значение!" << endl;
													correct = 0;
													break;
												}
												else
													correct = 1;
											}
											if (correct == 1)
											{
												hp_value[0].setCost(atoi(buff_s.c_str()));
												check = 0;
											}
										}
										push_tail(HP, deq_size, hp_value);
										sub_menu_0 = 0;
										break;
									}
									case '2':
									{
										pop_head(HP, deq_size);
										sub_menu_0 = 0;
										break;
									}
									case '3':
									{
										pop_tail(HP, deq_size);
										sub_menu_0 = 0;
										break;
									}
									case '4':
									{
										clear_deq(HP, deq_size);
										sub_menu_0 = 0;
										break;
									}
									case '5':
									{
										check_deq(deq_size);
										system("pause");
										sub_menu_0 = 0;
										break;
									}
									default:
									{
										sub_menu_0 = 0;
										break;
									}
									}
								}
							}
						}
						break;
					}
					case '1':
					{
						bool menu_0 = 1, sub_menu_0 = 1;
						while (menu_0)
						{
							sub_menu_0 = 1;
							system("cls");
							cout << "ДЕЙСТВИЯ С ЗАПИСЯМИ ДЕКА:" << endl;
							cout << "0. Вывести дек." << endl;
							cout << "1. Сортировка дека." << endl;
							cout << "2. Изменить запись дека." << endl;
							if (!_kbhit())
							{
								while (sub_menu_0)
								{
									switch (_getch())
									{
									case 27:
									{
										menu_0 = sub_menu_0 = sub_menu = 0;
										break;
									}
									case '0':
									{
										system("cls");
										if (deq_size != 0)
										{
											print_deq_table_format(HP, deq_size);
										}
										else
											cout << "Дек пуст. Нет информации для вывода" << endl;
										system("pause");
										sub_menu_0 = 0;
										break;
									}
									case '1':
									{
										system("cls");
										deq_sort(HP, deq_size);
										sub_menu_0 = 0;
										break;
									}
									case '2':
									{
										system("cls");
										print_deq_table_format(HP, deq_size);
										edit_deq(HP, deq_size);
										sub_menu_0 = 0;
										break;
									}
									default:
									{
										sub_menu_0 = 0;
										break;
									}
									}
								}
							}
						}
						break;
					}
					default:
					{
						sub_menu = 0;
						break;
					}
					}
				}
			}
		}
		delete[] HP;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double_ended_queue Deq;
	Deq.set_deq();
	system("pause");
	return 0;
}