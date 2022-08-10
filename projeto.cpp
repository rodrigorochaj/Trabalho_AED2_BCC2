#include <iostream>
#include <clocale>
#include <string.h>
using namespace std;

struct Alunos {
    int ra;
    string nome;
    string endereco;
    int telefone;
    string cidade;
    char uf[2];
};

struct Editoras {
    int cod_editora;
    string nome;
    string endereco;
    int telefone;
    string cidade;
    char uf[2];
};

struct Livros {
    int cod_livro;
    string descricao;
    int cod_editora;
    char situacao[1];
};

struct Emprestimos {
    int cod_emp;
    int ra_aluno;
    int cod_livro;
    int data_emp;
    int data_dev;
    char situacao;
};


void ler_alunos(struct Alunos a1[], int &ca){
    system ("cls");
    cout << "\n\nLeitura da Tabela de Alunos\n\n\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; i++){
        cout << "\nRA do Aluno: ";
        cin >> a1[i].ra;
        cin.ignore();
        cout << "Nome do Aluno: ";
        getline(cin, a1[i].nome);
        cout << "Endereço do Aluno: ";
        getline(cin, a1[i].endereco);
        cout << "Telefone do Aluno: ";
        cin >> a1[i].telefone;
        cin.ignore();
        cout << "Cidade do Aluno: ";
        getline(cin, a1[i].cidade);
        cout << "UF: ";
        cin >> a1[i].uf;

        cout << "\n\nDados inseridos com sucesso!";
        cout << "\nDeseja inserir um novo Aluno ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    ca = i;
    system ("pause");
}

void ler_editoras(struct Editoras e1[], int &ce){
    system ("cls");
    cout << "\n\nLeitura da Tabela de Editoras\n\n\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; i++){
        cout << "\nCódigo da Editora: ";
        cin >> e1[i].cod_editora;
        cout << "Nome do Editora: ";
        cin >> e1[i].nome;
        cout << "Endereço do Editora: ";
        cin >> e1[i].endereco;
        cout << "Telefone do Editora: ";
        cin >> e1[i].telefone;
        cout << "Cidade do Editora: ";
        cin >> e1[i].cidade;
        cout << "UF: ";
        cin >> e1[i].uf;

        cout << "\n\nDados inseridos com sucesso!";
        cout << "\nDeseja inserir uma nova Editora ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    ce = i;
    system ("pause");
}

void ler_livros(struct Livros l1[], int &cl){
    system ("cls");
    cout << "\n\nLeitura da Tabela de Livros\n\n\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; i++){
        cout << "\nCódigo da Livro: ";
        cin >> l1[i].cod_livro;
        cout << "Descrição do Livro: ";
        cin >> l1[i].descricao;
        cout << "Código da Editora: ";
        cin >> l1[i].cod_editora;
        cout << "Situação do Livro: ";
        cin >> l1[i].situacao;

        cout << "\n\nDados inseridos com sucesso!";
        cout << "\nDeseja inserir um novo Livro ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    cl = i;
    system ("pause");
}

void ler_emprestimos(struct Emprestimos emp1[], int &cemp){
    system ("cls");
    cout << "\n\nLeitura da Tabela de Empréstimos\n\n\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; i++){
        cout << "\nCódigo do Empréstimo: ";
        cin >> emp1[i].cod_emp;
        cout << "RA do Aluno: ";
        cin >> emp1[i].ra_aluno;
        cout << "Código do Livro: ";
        cin >> emp1[i].cod_livro;
        cout << "Data do Empréstimo: ";
        cin >> emp1[i].data_emp;
        cout << "Data de Devolução: ";
        cin >> emp1[i].data_dev;
        cout << "Situação: ";
        cin >> emp1[i].situacao;

        cout << "\n\nDados inseridos com sucesso!";
        cout << "\nDeseja inserir um novo Livro ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    cemp = i;
    system ("pause");
}

int main(){
    setlocale (LC_ALL, "Portuguese");

    struct Alunos a1[10];
    struct Editoras e1[10];
    struct Livros l1[10];
    struct Emprestimos emp1[10];
    int ca, ce, cl, cemp;
    char op = 'X';
    while (op != '0'){
            system ("cls");
            cout << "\n\n\t\t\tPrograma Arquivo Indexado\t\n\n\n";
            cout << "\n\t\t1- Ler Alunos";
            cout << "\n\t\t2- Ler Editoras";
            cout << "\n\t\t3- Ler Livros";
            cout << "\n\t\t4- Ler Emprestimos";
            cout << "\n\n\n\t\t0- Sair";
            cout << "\n\n\n\t\tEscolha uma opção : ";
            fflush(stdin);
            cin >> op;
            fflush(stdin);
            op = toupper(op);

            switch (op){
                    case '1': ler_alunos(a1, ca); break;
                    case '2': ler_editoras(e1, ce); break;
                    case '3': ler_livros(l1, cl); break;
                    case '4': ler_emprestimos(emp1, cemp); break;

                    case '0': system ("cls"); cout << "\n\n\n\n\n\t\t\t\tObrigado por usar nosso serviço.\n\n\n\n\n"; break;
                    default: cout << "\t\t\tOpção Inválida.\n\n"; break;
            }
    }
}
