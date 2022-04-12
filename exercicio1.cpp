#include <iostream>

using namespace std;

#define Y 15
#define X 40

int tabela(int fileira)
{
	if (fileira < 6)
		return 50;

	if (fileira < 11)
		return 30;

	return 15;
}

void reserva(char **poltronas, int *ocupados, int *faturamento)
{
	int fileira;
	int poltrona;

	cout << "fileira: ";
	cin >> fileira;

	while (fileira < 1 || fileira > Y)
	{
		cout << "fileira: ";
		cin >> fileira;
	};

	cout << "poltrona: ";
	cin >> poltrona;

	while (poltrona < 1 || poltrona > X)
	{
		cout << "poltrona: ";
		cin >> poltrona;
	};

	if (poltronas[fileira - 1][poltrona - 1] == '.')
	{
		poltronas[fileira - 1][poltrona - 1] = '#';

		*faturamento += tabela(fileira);

		*ocupados += 1;

		cout << "Reservado!";
	}
	else
	{
		cout << "N�o reservado!";
	}
}

void mapa(char **poltronas)
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cout << poltronas[i][j] << " | ";
		}

		cout << endl;
	}
}

void totalFat(int *ocupados, int *faturamento)
{
	cout << "Qtde de lugares ocupados: " << *ocupados << endl;

	cout << "Faturamento: " << *faturamento;
}

void menu(bool *finaliza, char **poltronas, int *faturamento, int *ocupados)
{
	int opt;

	cout << endl;
	cout << "0.	Finalizar" << endl;
	cout << "1.	Reservar poltrona" << endl;
	cout << "2.	Mapa de ocupa��o" << endl;
	cout << "3.	Faturamento" << endl;

	cout << "Digita ai: ";

	cin >> opt;

	switch (opt)
	{
	case 1:
		reserva(poltronas, ocupados, faturamento);
		break;
	case 2:
		mapa(poltronas);
		break;
	case 3:
		totalFat(ocupados, faturamento);
		break;
	default:
		*finaliza = true;
		break;
	}
}

int main()
{
	char **poltronas = new char *[Y];

	for (int i = 0; i < Y; i++)
	{
		char *fileira = new char[X];

		for (int j = 0; j < X; j++)
		{
			fileira[j] = '.';
		}

		poltronas[i] = fileira;
	}

	int faturamento = 0;

	int ocupados = 0;

	bool finaliza = false;

	while (!finaliza)
	{
		menu(&finaliza, poltronas, &ocupados, &faturamento);
	}

	return 0;
}