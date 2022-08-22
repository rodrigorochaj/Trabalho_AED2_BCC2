# ProgramaLivrariaAED22
Programa de Livraria 

Escreva um programa para criar as seguintes estruturas que simularão arquivos indexados:

Alunos: RA (PK), nome, endereço, telefone, cidade, UF

Editoras: código (PK), nome, endereço, telefone, cidade, UF

Livros: código (PK), descrição, cod_editora, situação (E/D) (Emprestado/Disponível)

Empréstimos: código (PK), RA_aluno, código_livro, data_empréstimo, data_devolução, situação (E/D) (Emprestado/Devolvido)



1) Escreva funções específicas para a leitura dos dados das estruturas

2) Escreva uma função para permitir a inclusão e a exclusão de registros na tabela de alunos.

3) Escreva uma função para permitir a inclusão e a exclusão de registros na tabela de editoras.

4) Escreva uma função para permitir a inclusão e a exclusão de registros na tabela de livros.

Obs: ao informar o código da editora, o nome da editora deverá ser exibido



5) Escreva uma função para registrar os empréstimos de livros na tabela de empréstimos.

Obs1: ao informar o RA_aluno, o nome do aluno deverá ser exibido e ao informar o código_livro, a descrição do livro deverá ser exibida

Obs2: não permitir o empréstimo de um livro que tenha situação = "E"

Obs3: quando um livro for emprestado, a situação do livro deverá ser alterada para "E" e a situação do empréstimo deve ser registrada como "E"



6) Escreva uma função para permitir a exclusão de registros da tabela de empréstimos.



7) Escreva uma função para registrar as devoluções de livros na tabela de empréstimos.

Obs: ao confirmar a devolução de um livro, a situação do livro deverá ser alterada para "D" e a situação do empréstimo deve ser registrada como "D"



8) Escreva uma função para listar todos os empréstimos que estão com a data de devolução atrasada

OBS: o código foi feito em uma única página, conforme solicitado pelo professor.

