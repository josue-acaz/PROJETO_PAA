 #!/bin/bash

echo "Compilando..."
if ! g++ source/main.cpp source/Problems.cpp source/Teste.cpp -o bin/Debug/np.out
then
    echo "Erro ao compilar!"
    exit 1
fi
echo "Compilação bem sucedida!"

echo "Executando..."
if ! ./bin/Debug/np.out
then
    echo "Execução bem sucedida!"
    exit 1
fi
echo "Process terminated with status (0)!"
