#include <iostream>
#include "fila.h"

using namespace std;

void PrintFront(const Fila& fila)
{
	Retorno ret = Front(fila);
	if (ret.codigo == -1)
		cout << "Fila vazia.\n";
	else
		cout << "Inicio da fila: " << ret.valor << '\n';
}

void PrintEnqueue(Fila& fila, char valor)
{
	bool ok = Enqueue(fila, valor);
	cout << (ok ? "Valor inserido." : "Fila cheia.") << '\n';
}

void PrintDequeue(Fila& fila)
{
	Retorno ret = Dequeue(fila);
	if (ret.codigo == -1)
		cout << "Fila vazia.\n";
	else
		cout << "Valor removido da fila: " << ret.valor << '\n';
}

int main()
{
	Fila fila = Create();
	PrintFront(fila);
	
	PrintEnqueue(fila, 'A');
	PrintFront(fila);
	
	PrintEnqueue(fila, 'B');
	PrintFront(fila);
	
	PrintEnqueue(fila, 'C');
	PrintFront(fila);
	
	PrintDequeue(fila);
	PrintFront(fila);
	
	PrintDequeue(fila);
	PrintFront(fila);
	
	PrintDequeue(fila);
	PrintFront(fila);

	for (int i = 0; i < CAPACIDADE_FILA + 1; ++i)
	{
		PrintEnqueue(fila, (char)('A' + i));
		PrintFront(fila);
	}
	
	while (!IsEmpty(fila))
	{
		PrintDequeue(fila);
	}
}
