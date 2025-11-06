#include <iostream>
using namespace std;
#define  N 5

//guarda quantos cursos foram cadastrados e indica o próximo índice livre
int pos = 0;
//guarda quantos alunos foram cadastrados e indica o próximo índice livre
int alu = 0;

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

void listarAlunos(meuAluno vet[]){
    if (alu == 0){
        cout << "Nenhum aluno foi cadastrado.\n";
        return;
    }
    for(int i = 0; i < alu; i ++){ //percorre só os alunos já cadastrados, sem acessar posições vazias
        cout << "Nome: " << vet[i].nomeAluno << endl;
        cout << "Idade: " << vet[i].idadeAluno<< endl;
        cout << "Numero de matricula: " << vet[i].matriculaAluno << endl;
        cout << endl;
    }
}

void listarCursos( meuCurso vet[]){
    if (pos == 0) {
    cout << "Nenhum curso cadastrado.\n";
    return;
    }
    for(int i = 0; i<pos; i++){ //percorre só os cursos já cadastrados, sem acessar posições vazias

        cout << "Codigo: " << vet[i].codigoCurso << endl;
        cout << "Nome: " << vet[i].nomeCurso << endl;
        cout << "Carga horaria: " << vet[i].cargaHoraria << endl;
        cout << "Vagas: " << vet[i].qntVagas << endl;
        cout << endl;
    }
        
}

void adicionarCurso(meuCurso vet[], meuCurso c){
    if(pos < N)
        vet[pos++] = c; //adiciona um curso e aumenta o contador automaticamente
    else
        cout << "Lista cheia. Curso nao adicionado." << endl;
}

bool codigoExiste(meuCurso vet[], int cod){
    for(int i = 0; i < pos; i ++){
        if(vet[i].codigoCurso == cod){
            return true;
        }

        return false;
    }


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
    meuAluno esteAluno;

    mostrarMenu();
    cin >> opcao;

    while(opcao != 7){
        switch(opcao){
            case 1:
                cadastrarCurso(&esteCurso);

                if(codigoExiste(vetorCursos, esteCurso.codigoCurso)){
                    cout << "Esse codigo de curso ja esta cadastrado..." << endl;
                }   else{

                    adicionarCurso(vetorCursos, esteCurso);
                    cout << endl;
                    cout << "Curso cadastrado com sucesso!" << endl;
                    cout << endl;
                }
                break;
            case 2:
                cadastrarAluno(&esteAluno);
            case 3:
                listarCursos(vetorCursos);
                break;
            default:
                cout << endl;
                cout << "Opcao invalida. Digite novamente...";
                cout << endl;
                break;
        }
        mostrarMenu();
        cin >> opcao;
    }



    return 0;
}
