#include <iostream>
#include <vector>
#include <string>
using namespace std;


// =============================
// Classe base: Pessoa
// =============================
class Pessoa {
protected:
    string nome;
    int idade;


public:
    Pessoa(string nome, int idade) : nome(nome), idade(idade) {}
    virtual void exibirInfo() const {
        cout << "Nome: " << nome << "\nIdade: " << idade << endl;
    }
    string getNome() const { return nome; }
};


// =============================
// Classe Aluno
// =============================
class Aluno : public Pessoa {
private:
    int matricula;


public:
    Aluno(string nome, int idade, int matricula)
  : Pessoa(nome, idade), matricula(matricula) {}


    void exibirInfo() const override {
        cout << "=== Aluno ===" << endl;
        Pessoa::exibirInfo();
        cout << "Matricula: " << matricula << endl;
    }


    int getMatricula() const { return matricula; }
};


// =============================
// Classe Alunos (sistema de alunos)
// =============================
class Alunos {
private:
    vector<Aluno> lista;


public:
    void adicionar(const Aluno &aluno) {
        lista.push_back(aluno);
    }


    void listar() const {
        cout << "\n=== Lista de Alunos ===" << endl;
        for (const auto &a : lista) {
            a.exibirInfo();
            cout << endl;
        }
    }


    void buscar(int matricula) const {
        bool encontrado = false;
        for (const auto &a : lista) {
 if (a.getMatricula() == matricula) {
                cout << "\nAluno encontrado:" << endl;
                a.exibirInfo();
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
            cout << "\nAluno nao encontrado!" << endl;
    }


    vector<Aluno> getLista() const {
        return lista;
    }
};


// =============================
// Classe Professor
// =============================
class Professor : public Pessoa {
private:
    string disciplina;


public:
    Professor(string nome, int idade, string disciplina)
        : Pessoa(nome, idade), disciplina(disciplina) {}


    void exibirInfo() const override {
        cout << "=== Professor ===" << endl;
        Pessoa::exibirInfo();
        cout << "Disciplina: " << disciplina << endl;
    }


    string getDisciplina() const { return disciplina; }
};


// =============================
// Classe Turma
// =============================
class Turma {
private:
    string codigo;
    Professor professor;
    vector<Aluno> alunos;


public:
    Turma(string codigo, Professor professor)
        : codigo(codigo), professor(professor) {}


    void adicionarAluno(const Aluno &aluno) {
        alunos.push_back(aluno);
    }


    void exibirTurma() const {
        cout << "\n===== Turma " << codigo << " =====" << endl;
        cout << "Professor responsavel:" << endl;
        professor.exibirInfo();
        cout << "\n--- Alunos ---" << endl;
        for (const auto &a : alunos) {
            a.exibirInfo();
            cout << endl;
        }
    }


    string getCodigo() const { return codigo; }
};


// =============================
// Classe Setor
// =============================
class Setor {
private:
    string nome;
    Pessoa responsavel;


public:
    Setor(string nome, Pessoa responsavel)
        : nome(nome), responsavel(responsavel) {}


    void exibirSetor() const {
        cout << "\n=== Setor: " << nome << " ===" << endl;
        cout << "Responsavel: " << responsavel.getNome() << endl;
    }


    string getNome() const { return nome; }
};


// =============================
// Classe Secretaria (controladora do sistema)
// =============================
class Secretaria {
private:
    vector<Turma> turmas;
    Alunos alunos;
    vector<Professor> professores;
    vector<Setor> setores;


public:
    // Cadastro
    void cadastrarAluno(const Aluno &aluno) { alunos.adicionar(aluno); }
    void cadastrarProfessor(const Professor &professor) { professores.push_back(professor); }
    void criarTurma(const Turma &turma) { turmas.push_back(turma); }
    void cadastrarSetor(const Setor &setor) { setores.push_back(setor); }


    // Listagens
    void listarAlunos() const { alunos.listar(); }


    void listarTurmas() const {
        cout << "\n=== Turmas Cadastradas ===" << endl;
        for (const auto &t : turmas)
            t.exibirTurma();
    }


    void listarSetores() const {
        cout << "\n=== Setores da Escola ===" << endl;
        for (const auto &s : setores)
            s.exibirSetor();
    }


    // Busca
    void buscarAluno(int matricula) const { alunos.buscar(matricula); }
};


// =============================
// Função principal
// =============================
int main() {
    Secretaria secretaria;


    // Professores
    Professor prof1("Kátia Barbosa", 40, "Matematica");
    Professor prof2( "Anusa Patricia", 35, "Historia");
    Professor prof3("Cristiane Baliero", 44,"Português");
    Professor prof4("Andressa Souza", 40,"Educação Física");
    Professor prof5("Paulo Medeiros", 44,"Inglês");   
    Professor prof6("Lorena Campos", 34,"Quimica");
    Professor prof7("Deyla Garces", 46,"Filosofia");
    Professor prof8("Cleise Aquino", 50,"Biologia");
    Professor prof9("Lucas Marinho", 38,"Fisica");
    Professor prof10("Denilson Silva", 44,"Geografia");
    Professor prof11("Andressa Souza", 44,"Arte");
    Professor prof12("Dayla Garces", 44,"Sociologia");
    Professor prof13("Katia Barbosa", 40,"Let.Matematica");
    Professor prof14("Paulo Medeiros", 44,"Linguagem");
    Professor prof15("Pricila Leyliane", 44,"Epaem");
    secretaria.cadastrarProfessor(prof1);
    secretaria.cadastrarProfessor(prof2);
    secretaria.cadastrarProfessor(prof3);
    secretaria.cadastrarProfessor(prof4);
    secretaria.cadastrarProfessor(prof5);
    secretaria.cadastrarProfessor(prof6);
    secretaria.cadastrarProfessor(prof7);
    secretaria.cadastrarProfessor(prof8);
    secretaria.cadastrarProfessor(prof9);
    secretaria.cadastrarProfessor(prof11);
    secretaria.cadastrarProfessor(prof10);
    secretaria.cadastrarProfessor(prof12);
    secretaria.cadastrarProfessor(prof13);
    secretaria.cadastrarProfessor(prof14);
    secretaria.cadastrarProfessor(prof15);
    
    // Alunos
    Aluno a1("Ana Ester", 15, 101);
    Aluno a2("Ana Julia", 16, 102);
    Aluno a3("Argenis", 17, 103);
    Aluno a4("Bruno", 15, 104);
    Aluno a5("Edma", 16, 105);
    Aluno a6("Francinei", 16, 106);
    Aluno a7("Francisco", 16, 107);
    Aluno a8("Gustavo", 15, 108);
    Aluno a9("Helio", 15, 109);
    Aluno a10("Henrique", 16, 111);
    Aluno a12("Jhonata", 15, 112);
    Aluno a13("Joao", 16, 113);
    Aluno a14("John", 15, 114);
    Aluno a15("Julita", 15, 115);
    Aluno a16("Leo", 16, 116);
    Aluno a17("Maria Eduarda", 16, 117);
    Aluno a18("Maria Luiza", 16, 118);
    Aluno a19("Miguel", 16, 119);
    Aluno a20("Nayanne", 16, 120);
    Aluno a21("Nicole", 16, 121);
    Aluno a22("Otavio", 16, 122);
    Aluno a23("Shymenne", 16, 123);
    Aluno a24("Vitoria", 16, 124);
    Aluno a25("Yasmin", 16, 125);
    secretaria.cadastrarAluno(a1);
    secretaria.cadastrarAluno(a2);
    secretaria.cadastrarAluno(a3);
    secretaria.cadastrarAluno(a4);
    secretaria.cadastrarAluno(a5);
    secretaria.cadastrarAluno(a6);
    secretaria.cadastrarAluno(a7);
    secretaria.cadastrarAluno(a8);
    secretaria.cadastrarAluno(a9);
    secretaria.cadastrarAluno(a10);
    secretaria.cadastrarAluno(a11);
    secretaria.cadastrarAluno(a12);
    secretaria.cadastrarAluno(a13);
    secretaria.cadastrarAluno(a14);
    secretaria.cadastrarAluno(a15);
    secretaria.cadastrarAluno(a16);
    secretaria.cadastrarAluno(a17);
    secretaria.cadastrarAluno(a18);
    secretaria.cadastrarAluno(a19);
    secretaria.cadastrarAluno(a20);
    secretaria.cadastrarAluno(a21);
    secretaria.cadastrarAluno(a22);
    secretaria.cadastrarAluno(a23);
    secretaria.cadastrarAluno(a24);
    secretaria.cadastrarAluno(a25);



    // Turmas
    Turma t1("A1", prof1);
    t1.adicionarAluno(a1);
    t1.adicionarAluno(a2);
    t1.adicionarAluno(a4);
    t1.adicionarAluno(a5);
    t1.adicionarAluno(a6);
    t1.adicionarAluno(a7);
    t1.adicionarAluno(a8);
    t1.adicionarAluno(a9);
    t1.adicionarAluno(a10);
    t1.adicionarAluno(a12);
    t1.adicionarAluno(a13);
    



    Turma t2("B2", prof2);
    t2.adicionarAluno(a3);
    secretaria.criarTurma(t13);
    secretaria.criarTurma(t14);
    secretaria.criarTurma(t15);
    secretaria.criarTurma(t16);
    secretaria.criarTurma(t17);
    secretaria.criarTurma(t18);
    secretaria.criarTurma(t19);
    secretaria.criarTurma(t20);
    secretaria.criarTurma(t21);
    secretaria.criarTurma(t22);
    secretaria.criarTurma(t24);


    // Setores
    Pessoa func1("Fernanda Alves", 32);
    Pessoa func2("Ricardo Lima", 45);
    Setor s1("Secretaria", func1);
    Setor s2("Biblioteca", func2);
    secretaria.cadastrarSetor(s1);
    secretaria.cadastrarSetor(s2);


// Exibições
    secretaria.listarAlunos();
    secretaria.buscarAluno(102);
    secretaria.listarTurmas();
    secretaria.listarSetores();


    return 0;
}