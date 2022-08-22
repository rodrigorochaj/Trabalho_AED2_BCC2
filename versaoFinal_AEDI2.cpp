#include <iostream>
#include <clocale>
#include <string.h>
#include <ctime>
using namespace std;

struct Alunos {
    int ra;
    string nome;
    string endereco;
    int telefone;
    string cidade;
    char uf[2];
    int status;
};

struct Editoras {
    int cod_editora;
    string nome;
    string endereco;
    int telefone;
    string cidade;
    char uf[2];
    int status;
};

struct Livros {
    int cod_livro;
    string descricao;
    int cod_editora;
    char situacao;
    int status;
};

struct Emprestimos {
    int cod_emp;
    int ra_aluno;
    int cod_livro;
    int dia_emp;
    int mes_emp;
    int ano_emp;
    int dia_dev;
    int mes_dev;
    int ano_dev;
    char situacao;
    int status;
};

struct Index {
    int cod;
    int end;
};

struct IndexAlunos {
    int ra;
    int end;
};

// Indice
void ler_index(struct Index idx[], int cont) {
    cout << "\n\n\nLeitura da Tabela de Indice" << endl;
    for (int i = 0; i < cont; i++){
        cout << "\nCódigo: ";
        cin >> idx[i].cod;
        cout << "Endereco Físico na Área de Dados: ";
        cin >> idx[i].end;
    }
}

void ler_indexAlunos(struct IndexAlunos idx[], int cont) {
    cout << "\n\n\nLeitura da Tabela de Indice" << endl;
    for (int i = 0; i < cont; i++){
        cout << "\nRA: ";
        cin >> idx[i].ra;
        cout << "Endereco Físico na Área de Dados: ";
        cin >> idx[i].end;
        cout << endl;
    }
}
// Fim Indice


// Leitura
void ler_alunos(struct Alunos a1[], struct IndexAlunos ia1[], int &ca) {
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
        a1[i].status = 1;

        cout << "\nDeseja registrar um novo Aluno ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    ca = i;
    ler_indexAlunos(ia1, ca);
    cout << "\nAluno(s) Registrado(s) com sucesso!\n\n";
    system ("pause");
}

void ler_editoras(struct Editoras e1[], struct Index ie1[], int &ce) {
    system ("cls");
    cout << "\n\nLeitura da Tabela de Editoras\n\n\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; i++){
        cout << "\nCódigo da Editora: ";
        cin >> e1[i].cod_editora;
        cin.ignore();
        cout << "Nome da Editora: ";
        getline(cin, e1[i].nome);
        cout << "Endereço da Editora: ";
        getline(cin, e1[i].endereco);
        cout << "Telefone da Editora: ";
        cin >> e1[i].telefone;
        cin.ignore();
        cout << "Cidade da Editora: ";
        getline(cin, e1[i].cidade);
        cout << "UF: ";
        cin >> e1[i].uf;
        e1[i].status = 1;

        cout << "\nDeseja registrar uma nova Editora ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    ce = i;
    ler_index(ie1, ce);
    cout << "\nEditora(s) Registrada(s) com sucesso!\n\n";
    system ("pause");
}

void ler_livros(struct Livros l1[], struct Index il1[], int &cl) {
    system ("cls");
    cout << "\n\nLeitura da Tabela de Livros\n\n\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; i++){
        cout << "\nCódigo do Livro: ";
        cin >> l1[i].cod_livro;
        cin.ignore();
        cout << "Descriç?o do Livro: ";
        getline(cin, l1[i].descricao);
        cout << "Código da Editora: ";
        cin >> l1[i].cod_editora;
        l1[i].situacao = 'D';
        l1[i].status = 1;

        cout << "\nDeseja registrar um novo Livro ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    cl = i;
    ler_index(il1, cl);
    cout << "\nLivro(s) Registrado(s) com sucesso!\n\n";
    system ("pause");
}
// Fim Leitura


// Busca
void busca_editora(int cod, struct Editoras e1[], struct Index ie1[], int ce) {
    int i = 0, f = ce;
    int m = (i + f) / 2;
    for (; f >= i && cod != ie1[m].cod; m = (i + f) / 2){
        if (cod > ie1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == ie1[m].cod){
        i = ie1[m].end;
        cout << "Editora: " << e1[i].nome;
    }
    else
        cout << "\n\n Editora n?o Encontrada";
}

void busca_aluno(int ra, struct Alunos a1[], struct IndexAlunos ia1[], int ca) {
    int i = 0, f = ca-1;
    int m = (i + f) / 2;
    for (; f >= i && ra != ia1[m].ra; m = (i + f) / 2){
        if (ra > ia1[m].ra)
            i = m + 1;
        else
            f = m - 1;
    }
    if (ra == ia1[m].ra){
        i = ia1[m].end;
        cout << a1[i].nome;
    }
    else
        cout << "\n\nAluno não Encontrado";

}

void busca_livro(int cod, struct Livros l1[], struct Index il1[], int cl, char &situ, int &idx) {
    int i = 0, f = cl-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != il1[m].cod; m = (i + f) / 2){
        if (cod > il1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == il1[m].cod){
        idx = il1[m].end;
        situ = l1[idx].situacao;
        if (situ == 'E'){
            cout << "\n\nLivro Emprestado, escolha outro";
            return;
        }
        else {
            cout << l1[idx].descricao;
        }
    }
    else
        cout << "\n\nLivro não encontrado";
}

void busca_emprestimo_dev(int &cod, struct Emprestimos emp1[], struct Index iemp1[], int cemp) {
    int i = 0, f = cemp-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != iemp1[m].cod; m = (i + f) / 2){
        if (cod > iemp1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == iemp1[m].cod){
        i = iemp1[m].end;
        if (emp1[i].status == 1){
            if (emp1[i].situacao = 'E'){
                emp1[i].situacao = 'D';
                cod = emp1[i].cod_livro;
            }
            else {
                cout << "\n\nEmpréstimo já foi devolvido";
            }
        }
        else {
            cout << "\n\nEmpréstimo não encontrado";
        }
    }
    else
        cout << "\n\nEmpréstimo não encontrado";
}

void busca_livro_dev(int cod, struct Livros l1[], struct Index il1[], int cl) {
    int i = 0, f = cl-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != il1[m].cod; m = (i + f) / 2){
        if (cod > il1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == il1[m].cod){
        i = il1[m].end;
        l1[i].situacao = 'D';
    }
}
// Fim Busca


// Inclusao
void incluir_alunos (struct Alunos a1[], struct IndexAlunos ia1[], int &ca) {
    system("cls");
    cout << "\n\nIncluir Registros na Tabela de Alunos\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; ca++){
        cout << "\nRA do Aluno: ";
        cin >> a1[ca].ra;
        cin.ignore();
        cout << "Nome do Aluno: ";
        getline(cin, a1[ca].nome);
        cout << "Endereço do Aluno: ";
        getline(cin, a1[ca].endereco);
        cout << "Telefone do Aluno: ";
        cin >> a1[ca].telefone;
        cin.ignore();
        cout << "Cidade do Aluno: ";
        getline(cin, a1[ca].cidade);
        cout << "UF: ";
        cin >> a1[ca].uf;
        a1[ca].status = 1;

        for (i = ca - 1; ia1[i].ra > a1[ca].ra; i--){
            ia1[i+1].ra = ia1[i].ra;
            ia1[i+1].end = ia1[i].end;
        }
        ia1[i+1].ra = a1[ca].ra;
        ia1[i+1].end = ca;
        cout << "\n\nInclusao realizada com Sucesso";

        cout << "\nDeseja incluir um novo Aluno ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
     cout << "\nAluno(s) Registrado(s) com sucesso!\n\n";
    system("pause");
}

void incluir_editoras (struct Editoras e1[], struct Index ie1[], int &ce) {
    system("cls");
    cout << "\n\nIncluir Registros na Tabela de Editoras\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; ce++){
        cout << "\nCódigo da Editora: ";
        cin >> e1[ce].cod_editora;
        cin.ignore();
        cout << "Nome da Editora: ";
        getline(cin, e1[ce].nome);
        cout << "Endereço da Editora: ";
        getline(cin, e1[ce].endereco);
        cout << "Telefone da Editora: ";
        cin >> e1[ce].telefone;
        cin.ignore();
        cout << "Cidade da Editora: ";
        getline(cin, e1[ce].cidade);
        cout << "UF: ";
        cin >> e1[ce].uf;
        e1[ce].status = 1;

        for (i = ce - 1; ie1[i].cod > e1[ce].cod_editora; i--){
            ie1[i+1].cod = ie1[i].cod;
            ie1[i+1].end = ie1[i].end;
        }
        ie1[i+1].cod = e1[ce].cod_editora;
        ie1[i+1].end = ce;
        cout << "\n\nInclusao realizada com Sucesso";

        cout << "\nDeseja incluir uma nova Editora ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    cout << "\nEditora(s) Registrada(s) com sucesso!\n\n";
    system("pause");
}

void incluir_livros (struct Livros l1[], struct Editoras e1[], struct Index il1[], struct Index ie1[], int &cl, int ce) {
    system("cls");
    cout << "\n\nIncluir Registros na Tabela de Livros\n";
    int i = 0;
    char resp = 'X';
    for (; resp != 'N'; cl++){
        cout << "\nCódigo do Livro: ";
        cin >> l1[cl].cod_livro;
        cin.ignore();
        cout << "Descriç?o do Livro: ";
        getline(cin, l1[cl].descricao);
        cout << "Código da Editora: ";
        cin >> l1[cl].cod_editora;
        busca_editora(l1[cl].cod_editora, e1, ie1, ce);
        l1[cl].situacao = 'D';
        l1[cl].status = 1;

        for (i = cl - 1; il1[i].cod > l1[cl].cod_livro; i--){
            il1[i+1].cod = il1[i].cod;
            il1[i+1].end = il1[i].end;
        }
        il1[i+1].cod = l1[cl].cod_livro;
        il1[i+1].end = cl;
        cout << "\n\nInclusao realizada com Sucesso";

        cout << "\nDeseja incluir um novo Livro ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
    }
    cout << "\nLivro(s) Registrado(s) com sucesso!\n\n";
    system("pause");
}

void emprestar(struct Emprestimos emp1[], struct Alunos a1[], struct Livros l1[], struct Index iemp1[], struct IndexAlunos ia1[], struct Index il1[], int &cemp, int ca, int cl) {
    system ("cls");
    cout << "\n\nEmprestar\n\n\n";
    int i = 0, idx = 0;
    char resp = 'X', situ = 'E';
    for (; resp != 'N'; cemp++){
        cout << "\nCódigo do Empréstimo: ";
        cin >> emp1[cemp].cod_emp;
        cout << "RA do Aluno: ";
        cin >> emp1[cemp].ra_aluno;
        busca_aluno(emp1[cemp].ra_aluno, a1, ia1, ca);
        while (situ == 'E'){
            cout << "\n\nCódigo do Livro: ";
            cin >> emp1[cemp].cod_livro;
            busca_livro(emp1[cemp].cod_livro, l1, il1, cl, situ, idx);
        }
        cout << "\nDia Empréstimo: ";
        cin >> emp1[cemp].dia_emp;
        cout << "Mes Empréstimo: ";
        cin >> emp1[cemp].mes_emp;
        cout << "Ano Empréstimo: ";
        cin >> emp1[cemp].ano_emp;
        cout << "Dia Devolução: ";
        cin >> emp1[cemp].dia_dev;
        cout << "Mes Devolução: ";
        cin >> emp1[cemp].mes_dev;
        cout << "Ano Devolução: ";
        cin >> emp1[cemp].ano_dev;
        emp1[cemp].situacao = 'E';
        emp1[cemp].status = 1;
        l1[idx].situacao = 'E';

        if (cemp == 0){
            ler_index(iemp1, 1);
        }
        else {
            for (i = cemp - 1; iemp1[i].cod > emp1[cemp].cod_emp; i--){
                iemp1[i+1].cod = iemp1[i].cod;
                iemp1[i+1].end = iemp1[i].end;
            }
            iemp1[i+1].cod = emp1[cemp].cod_emp;
            iemp1[i+1].end = cemp;
        }

        cout << "\nDeseja inserir um novo Empréstimo ? (S/N) : ";
        cin >> resp;
        resp = toupper(resp);
        situ = 'E';
    }
    cout << "\nEmpréstimo(s) Registrado(s) com Sucesso!\n\n";
    system ("pause");
}
// Fim Inclusao


void devolver(struct Emprestimos emp1[], struct Livros l1[], struct Index iemp1[], struct Index il1[], int &cemp, int cl) {
    system ("cls");
    cout << "\n\nDevolver\n\n\n";
    int cod;

    cout << "Informe o Código do Emprestimo para devolução :";
    cin >> cod;
    busca_emprestimo_dev(cod, emp1, iemp1, cemp);
    busca_livro_dev(cod, l1, il1, cl);

    cout << "Devolução feita com sucesso !\n\n";
    system ("pause");
}


// Exclusao
void excluir_alunos(struct Alunos a1[], struct IndexAlunos ia1[], int &ca) {
    system("cls");
    cout << "\n\nExcluir Registro da Tabela Alunos\n\n";

    int i = 0, f = ca, ra;
    int m = (i + f) / 2;
    char resp = 'X';


    while(resp != 'N'){
        cout << "Informe o RA do Aluno que deseja excluir :";
        cin >> ra;

        for (; f >= i && ra != ia1[m].ra; m = (i + f) / 2){
            if (ra > ia1[m].ra)
                i = m + 1;
            else
                f = m - 1;
        }
        i = ia1[m].end;
        if ((ra == ia1[m].ra) && a1[i].status == 1){
            a1[i].status = 0;
            cout << "Aluno Excluido com Sucesso.\n";
            cout << "Deseja Excluir outro Aluno ? (S/N) : ";
            cin >> resp;
        }
        else {
            cout << "Aluno não cadastrado.\n";
            cout << "Deseja tentar novamente ? (S/N) : ";
            cin >> resp;
        }
        resp = toupper(resp);
    }
    cout << "\n\n";
    system("pause");
}

void excluir_editoras(struct Editoras e1[], struct Index ie1[], int &ce) {
    system("cls");
    cout << "\n\nExcluir Registro da Tabela Editoras\n\n";

    int i = 0, f = ce, cod;
    int m = (i + f) / 2;
    char resp = 'X';

    while(resp != 'N'){
        cout << "Informe o Código da Editora que deseja excluir :";
        cin >> cod;

        for (; f >= i && cod != ie1[m].cod; m = (i + f) / 2){
            if (cod > ie1[m].cod)
                i = m + 1;
            else
                f = m - 1;
        }
        i = ie1[m].end;
        if ((cod == ie1[m].cod) && e1[i].status == 1){
            e1[i].status = 0;
            cout << "Editora Excluida com Sucesso.\n";
            cout << "Deseja Excluir outra Editora ? (S/N) : ";
            cin >> resp;
        }
        else {
            cout << "Editora não cadastrada.\n";
            cout << "Deseja tentar novamente ? (S/N) : ";
            cin >> resp;
        }
        resp = toupper(resp);
    }
    cout << "\n\n";
    system("pause");
}

void excluir_livros(struct Livros l1[], struct Index il1[], int &cl) {
    system("cls");
    cout << "\n\nExcluir Registro da Tabela Livros\n\n";

    int i = 0, f = cl, cod;
    int m = (i + f) / 2;
    char resp = 'X';

    while(resp != 'N'){
        cout << "Informe o Código do Livro que deseja excluir :";
        cin >> cod;

        for (; f >= i && cod != il1[m].cod; m = (i + f) / 2){
            if (cod > il1[m].cod)
                i = m + 1;
            else
                f = m - 1;
        }
        i = il1[m].end;
        if ((cod == il1[m].cod) && l1[i].status == 1){
            l1[i].status = 0;
            cout << "Livro Excluido com Sucesso.\n";
            cout << "Deseja Excluir outro Livro ? (S/N) : ";
            cin >> resp;
        }
        else {
            cout << "Livro n?o cadastrado.\n";
            cout << "Deseja tentar novamente ? (S/N) : ";
            cin >> resp;
        }
        resp = toupper(resp);
    }
    cout << "\n\n";
    system("pause");
}

void excluir_emprestimos(struct Emprestimos emp1[], struct Index iemp1[], int &cemp) {
    system("cls");
    cout << "\n\nExcluir Registro da Tabela Empréstimos\n\n";

    int i = 0, f = cemp, cod;
    int m = (i + f) / 2;
    char resp = 'X';

    while(resp != 'N'){
        cout << "Informe o Código do Empréstimo que deseja excluir :";
        cin >> cod;

        for (; f >= i && cod != iemp1[m].cod; m = (i + f) / 2){
            if (cod > iemp1[m].cod)
                i = m + 1;
            else
                f = m - 1;
        }
        i = iemp1[m].end;
        if ((cod == iemp1[m].cod) && emp1[i].status == 1){
            emp1[i].status = 0;
            cout << "Empréstimo Excluido com Sucesso.\n";
            cout << "Deseja Excluir outro Empréstimo ? (S/N) : ";
            cin >> resp;
        }
        else {
            cout << "Empréstimo n?o cadastrado.\n";
            cout << "Deseja tentar novamente ? (S/N) : ";
            cin >> resp;
        }
        resp = toupper(resp);
    }
    cout << "\n\n";
    system("pause");
}
// Fim Exclusao


// Impressao
void imprimir_alunos (struct Alunos a1[], struct IndexAlunos ia1[], int ca) {
    system ("cls");
    cout << "\n\n\t\t\tTabela Alunos\t\n\n\n";
    int i;
    cout << "Indice\n";
    for (i = 0; i < ca; i++){
        if (a1[i].status == 1){
            cout << "\nRA: " << ia1[i].ra;
            cout << "\nEnd: " << ia1[i].end << endl;
        }
    }
    cout << "\n\n\nDados\n";
    for (i = 0; i < ca; i++){
        if (a1[i].status == 1){
            cout << "\nRA do Aluno: " << a1[i].ra;
            cout << "\nNome do Aluno: " << a1[i].nome;
            cout << "\nEndereço do Aluno: " << a1[i].endereco;
            cout << "\nTelefone do Aluno: " << a1[i].telefone;
            cout << "\nCidade do Aluno: " << a1[i].cidade;
            cout << "\nUF: " << a1[i].uf << "\n";
        }
    }
    system ("pause");
}

void imprimir_editoras (struct Editoras e1[], struct Index ie1[], int ce) {
    system ("cls");
    cout << "\n\n\t\t\tTabela Editoras\t\n\n\n";
    int i;
    cout << "Indice\n";
    for (i = 0; i < ce; i++){
        if (e1[i].status == 1){
            cout << "\nCod Editora: " << ie1[i].cod;
            cout << "\nEnd Editora: " << ie1[i].end << endl;
        }
    }
    cout << "\n\n\nDados\n";
    for (i = 0; i < ce; i++){
        if (e1[i].status == 1){
            cout << "\nCódigo da Editora: " << e1[i].cod_editora;
            cout << "\nNome da Editora: " << e1[i].nome;
            cout << "\nEndereço da Editora: " << e1[i].endereco;
            cout << "\nTelefone da Editora: " << e1[i].telefone;
            cout << "\nCidade da Editora: " << e1[i].cidade;
            cout << "\nUF: " << e1[i].uf << "\n";
        }
    }
    system ("pause");
}

void imprimir_livros (struct Livros l1[], struct Index il1[], int cl) {
    system ("cls");
    cout << "\n\n\t\t\tTabela Livros\t\n\n\n";
    int i;
    cout << "Indice\n";
    for (i = 0; i < cl; i++){
        if (l1[i].status == 1){
            cout << "\nCod Livro: " << il1[i].cod;
            cout << "\nEnd Livro: " << il1[i].end << endl;
        }
    }
    cout << "\n\n\nDados\n";
    for (i = 0; i < cl; i++){
        if (l1[i].status == 1){
            cout << "\nCódigo do Livro: " << l1[i].cod_livro;
            cout << "\nDescriç?o do Livro: " << l1[i].descricao;
            cout << "\nCódigo da Editora: " << l1[i].cod_editora;
            cout << "\nSituaç?o do Livro: " << l1[i].situacao << "\n";
        }
    }
    system ("pause");
}

void imprimir_emprestimos (struct Emprestimos emp1[], struct Index iemp1[], int cemp) {
    system ("cls");
    cout << "\n\n\t\t\tTabela Emprestimos\t\n\n\n";
    int i;
    cout << "Indice\n";
    for (i = 0; i < cemp; i++){
        if (emp1[i].status == 1){
            cout << "\nCod Emp: " << iemp1[i].cod;
            cout << "\nEnd Emp: " << iemp1[i].end;
        }
    }
    cout << "\n\n\nDados\n";
    for (i = 0; i < cemp; i++){
        if (emp1[i].status == 1){
            cout << "\nCódigo do Empréstimo/Devolução: " << emp1[i].cod_emp;
            cout << "\nRA do Aluno: " << emp1[i].ra_aluno;
            cout << "\nCódigo do Livro: " << emp1[i].cod_livro;
            cout << "\nData Empréstimo: " << emp1[i].dia_emp << "/" << emp1[i].mes_emp << "/" << emp1[i].ano_emp;
            cout << "\nData Devolução: " << emp1[i].dia_dev << "/" << emp1[i].mes_dev << "/" << emp1[i].ano_dev;
            cout << "\nSituação: " << emp1[i].situacao << "\n";
        }
    }
    system ("pause");
}
// Fim Impressao

void emprestimos_atrasados(struct Emprestimos emp1[], struct Index iemp1[], int cemp) {
    system("cls");

    cout << "\n\nEmprestimos Atrasados\n\n";
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int data_dev, data_atual, x_mes, x_mes2, aux, aux2 = 0;
    int ano_atual =  1900 + ltm->tm_year;
    int mes_atual =  1 + ltm->tm_mon;
    int dia_atual = ltm->tm_mday;

    for (int i = 0; i < cemp; i++){
        aux = iemp1[i].end;

        if (emp1[aux].status == 1 && emp1[aux].situacao == 'E'){
            if (emp1[aux].mes_dev == 2){
                x_mes = 28;
            }
            else if (emp1[aux].mes_dev == 4 || emp1[aux].mes_dev == 6 || emp1[aux].mes_dev == 9 || emp1[aux].mes_dev == 11){
                x_mes = 30;
            }
            else x_mes = 31;

            if (mes_atual == 2){
                x_mes2 = 28;
            }
            else if (mes_atual == 4 || mes_atual == 6 || mes_atual == 9 || mes_atual == 11){
                x_mes2 = 30;
            }
            else x_mes2 = 31;

            data_dev = emp1[aux].ano_dev * 365 + emp1[aux].mes_dev * x_mes + emp1[aux].dia_dev;
            data_atual = ano_atual * 365 + mes_atual * x_mes2 + dia_atual;

            if (data_dev - data_atual < 1){
                cout << "\nCódigo do Empréstimo/Devolução: " << emp1[aux].cod_emp;
                cout << "\nRA do Aluno: " << emp1[aux].ra_aluno;
                cout << "\nCódigo do Livro: " << emp1[aux].cod_livro;
                cout << "\nData Empréstimo: " << emp1[aux].dia_emp << "/" << emp1[aux].mes_emp << "/" << emp1[aux].ano_emp;
                cout << "\nData Devolução: " << emp1[aux].dia_dev << "/" << emp1[aux].mes_dev << "/" << emp1[aux].ano_dev << "\n\n";
            }
            aux2 = 1;
        }
    }
    if (aux2 == 0){
        cout << "Não há Empréstimos atrasados.\n\n";
    }
    system ("pause");

}

// Menus
void menu_alunos(struct Alunos a1[], struct IndexAlunos ia1[], int &ca) {
    char op = 'X';
    while (op != '0'){
        system ("cls");
        cout << "\n\n\t\t\tMenu Aluno\t\n\n\n";
        cout << "\n\t\t1- Ler Alunos";
        cout << "\n\t\t2- Incluir Alunos";
        cout << "\n\t\t3- Excluir Alunos";
        cout << "\n\t\t4- Imprimir Alunos";
        cout << "\n\n\n\t\t0- Voltar";
        cout << "\n\n\n\t\tEscolha uma opção : ";
        fflush(stdin);
        cin >> op;
        fflush(stdin);
        op = toupper(op);

        switch (op){
            case '1': ler_alunos(a1, ia1, ca); break;
            case '2': incluir_alunos(a1, ia1, ca); break;
            case '3': excluir_alunos(a1, ia1, ca); break;
            case '4': imprimir_alunos(a1, ia1, ca); break;
            case '0': system ("cls");
            default: cout << "\t\t\tOpção Inválida.\n\n"; break;
        }
    }
}

void menu_editoras(struct Editoras e1[], struct Index ie1[], int &ce) {
    char op = 'X';
    while (op != '0'){
        system ("cls");
        cout << "\n\n\t\t\tMenu Editoras\t\n\n\n";
        cout << "\n\t\t1- Ler Editoras";
        cout << "\n\t\t2- Incluir Editoras";
        cout << "\n\t\t3- Excluir Editoras";
        cout << "\n\t\t4- Imprimir Editoras";
        cout << "\n\n\n\t\t0- Voltar";
        cout << "\n\n\n\t\tEscolha uma opção : ";
        fflush(stdin);
        cin >> op;
        fflush(stdin);
        op = toupper(op);

        switch (op){
            case '1': ler_editoras(e1, ie1, ce); break;
            case '2': incluir_editoras(e1, ie1, ce); break;
            case '3': excluir_editoras(e1, ie1, ce); break;
            case '4': imprimir_editoras(e1, ie1, ce); break;
            case '0': system ("cls");
            default: cout << "\t\t\tOpção Inválida.\n\n"; break;
        }
    }
}

void menu_livros(struct Livros l1[], struct Editoras e1[], struct Index il1[], struct Index ie1[], int &cl, int ce) {
    char op = 'X';
    while (op != '0'){
        system ("cls");
        cout << "\n\n\t\t\tMenu Livros\t\n\n\n";
        cout << "\n\t\t1- Ler Livros";
        cout << "\n\t\t2- Incluir Livros";
        cout << "\n\t\t3- Excluir Livros";
        cout << "\n\t\t4- Imprimir Livros";
        cout << "\n\n\n\t\t0- Voltar";
        cout << "\n\n\n\t\tEscolha uma opção : ";
        fflush(stdin);
        cin >> op;
        fflush(stdin);
        op = toupper(op);

        switch (op){
            case '1': ler_livros(l1, il1, cl); break;
            case '2': incluir_livros(l1, e1, il1, ie1, cl, ce); break;
            case '3': excluir_livros(l1, il1, cl); break;
            case '4': imprimir_livros(l1, il1, cl); break;
            case '0': system ("cls");
            default: cout << "\t\t\tOpção Inválida.\n\n"; break;
        }
    }
}

void menu_emprestimos(struct Emprestimos emp1[], struct Index iemp1[], int &cemp, struct Alunos a1[], struct IndexAlunos ia1[], int ca, struct Livros l1[], struct Index il1[], int cl) {
    char op = 'X';
    while (op != '0'){
        system ("cls");
        cout << "\n\n\t\t\tMenu Emprestimos\t\n\n\n";
        cout << "\n\t\t1- Emprestar";
        cout << "\n\t\t2- Devolver";
        cout << "\n\t\t3- Excluir Emprestimos/Devoluç?es";
        cout << "\n\t\t4- Imprimir Emprestimos/Devoluç?es";
        cout << "\n\t\t5- Imprimir Emprestimos Atrasados";
        cout << "\n\n\n\t\t0- Voltar";
        cout << "\n\n\n\t\tEscolha uma opção : ";
        fflush(stdin);
        cin >> op;
        fflush(stdin);
        op = toupper(op);

        switch (op){
            case '1': emprestar(emp1, a1, l1, iemp1, ia1, il1, cemp, ca, cl); break;
            case '2': devolver(emp1, l1, iemp1, il1, cemp, cl); break;
            case '3': excluir_emprestimos(emp1, iemp1, cemp); break;
            case '4': imprimir_emprestimos(emp1, iemp1, cemp); break;
            case '5': emprestimos_atrasados(emp1, iemp1, cemp); break;
            case '0': system ("cls");
            default: cout << "\t\t\tOpção Inválida.\n\n"; break;
        }
    }
}
// Fim Menus


int main(){
    setlocale (LC_ALL, "Portuguese");

    struct Alunos a1[10];
    struct Editoras e1[10];
    struct Livros l1[10];
    struct Emprestimos emp1[10];
    struct Index ie1[10], il1[10], iemp1[10];
    struct IndexAlunos ia1[10];
    int ca = 0, ce = 0, cl = 0, cemp = 0;
    char op = 'X';
    while (op != '0'){
        system ("cls");
        cout << "\n\n\t\t\tPrograma Arquivo Indexado\t\n\n\n";
        cout << "\n\t\t1- Menu Alunos";
        cout << "\n\t\t2- Menu Editoras";
        cout << "\n\t\t3- Menu Livros";
        cout << "\n\t\t4- Menu Empréstimos";

        cout << "\n\n\n\t\t0- Sair";
        cout << "\n\n\n\t\tEscolha uma opção : ";
        fflush(stdin);
        cin >> op;
        fflush(stdin);
        op = toupper(op);

        switch (op){
            case '1': menu_alunos(a1, ia1, ca); break;
            case '2': menu_editoras(e1, ie1, ce); break;
            case '3': menu_livros(l1, e1, il1, ie1, cl, ce); break;
            case '4': menu_emprestimos(emp1, iemp1, cemp, a1, ia1, ca, l1, il1, cl); break;
            case '0': system ("cls"); cout << "\n\n\n\n\n\t\t\t\tObrigado por usar nosso serviço.\n\n\n\n\n"; break;
            default: cout << "\t\t\tOpção Inválida.\n\n"; break;
        }
    }
}


