#include <iostream>
using namespace std;
#define  N 5

int pos = 0;

struct meuCurso{
    int codigoCurso;
    string nomeCurso;
    int cargaHoraria;
    int qntVagas;
};

struct meuAluno{
    int matriculaAluno;
    string nomeAluno;
    int idadeAluno;
};

void cadastrarAluno(meuAluno *a) {
    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, a->nomeAluno);
    cout << "Digite a matricula: ";
    cin >> a->matriculaAluno;
    cout << "Digite a idade: ";
    cin >> a->idadeAluno;
}

void cadastrarCurso(meuCurso *c) {
    cout << "Digite o nome do curso: ";
    cin.ignore();
    getline(cin, c->nomeCurso);
    cout << "Digite a carga horaria: ";
    cin >> c->cargaHoraria;
    cout << "Digite a quantidade de vagas: ";
    cin >> c->qntVagas;
    cout << "Digite o codigo do curso: ";
    cin >> c->codigoCurso;
}

void listarCursos( meuCurso vet[]){
    for(int i = 0; i<pos; i++){

        cout << "Codigo do curso: " << endl;
        cout << "Nome do curso: " << vet->nomeCurso << endl;
        cout << "Carga horaria do curso: " << vet->cargaHoraria << endl;
        cout << "Vagas do curso: " << vet->qntVagas << endl;
    }
        
}

void adicionarCurso(meuCurso vet[], meuCurso c){
    if(pos < N)
        vet[pos++] = c;
    else
        cout << "Lista cheia. Curso nao adicionado." << endl;
}

void mostrarMenu(){
    cout << "------------------ MOSTRAR MENU ------------------" << endl;
    cout << "1 - para cadastrar curso" << endl;
    cout << "2 - para cadastrar aluno" << endl;
    cout << "3 - para listar cursos" << endl;
    cout << "4 - para listar alunos" << endl;
    cout << "5 - para buscar alunos por curso" << endl;
    cout << "6 - para mostrar quantos alunos em cada curso" << endl;
    cout << "7 - para sair" << endl;
}



int main(){
    int opcao;
    meuCurso esteCurso;
    meuCurso vetorCursos[N];

    mostrarMenu();
    cin >> opcao;

    while(opcao != 7){
        switch(opcao){
            case 1:
                cadastrarCurso(&esteCurso);
                adicionarCurso(vetorCursos, esteCurso);
                break;

            case 3:
                listarCursos(vetorCursos);
                break;
            default:
                cout << "Opcao invalida. Digite novamente...";
                break;
        }
        mostrarMenu();
        cin >> opcao;
    }



    return 0;
}
