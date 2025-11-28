#include <iostream>
#include <fstream>
#define MAX 200

using namespace std;
#define  N 50

//guarda quantos cursos foram cadastrados e indica o próximo índice livre
int pos = 0;
//guarda quantos alunos foram cadastrados e indica o próximo índice livre
int alu = 0;

int cid = 0;

struct meuCurso{
    int codigoCurso;
    char nomeCurso[100];
    int cargaHoraria;
    int qntVagas;
};

struct meuAluno{
    int matriculaAluno;
    char nomeAluno[100];
    int idadeAluno;
    int codigoCurso;
};

struct minhaCidade{
    char nomeCidade[100];
    char nomePais[100];
};


void cadastrarAluno(meuAluno *a, meuCurso vetCursos[], int totalCursos) {
    cout << "Digite o nome: ";
    cin.ignore();
    cin.getline(a->nomeAluno, 100);

    cout << "Digite a idade: ";
    cin >> a->idadeAluno;

    cout << "Digite a matricula: ";
    cin >> a->matriculaAluno;

    int cod;
    cout << "Digite o codigo do curso em que o aluno sera matriculado: ";
    cin >> cod;

    bool encontrado = false;
    for(int i = 0; i < totalCursos; i ++){
        if (vetCursos[i].codigoCurso == cod){
            encontrado = true;
            break;
        }
    }

    if(encontrado){
        a->codigoCurso = cod;
        cout << "Aluno matriculado no curso de codigo " << cod << " com sucesso!" << endl;

    } else{
        cout << "Curso nao encontrado! Aluno nao cadastrado.";
        a->codigoCurso = -1;
    }

}

void cadastrarCidade(minhaCidade *c){
    cout << "Digite o nome: ";
    cin.getline(c->nomeCidade, 100);
    cout << "Digite o pais: ";
    cin.getline(c->nomePais, 100);
}

void adicionarCidade(minhaCidade vet[], minhaCidade cida){
    if(cid < N)
        vet[cid++] = cida;
    else
        cout << "Cidades cheias, não cadastrado." << endl;
}

void cadastrarCurso(meuCurso *c) {
    cout << "Digite o nome do curso: ";
    cin.ignore();
    cin.getline(c->nomeCurso, 100);
    cout << "Digite a carga horaria: ";
    cin >> c->cargaHoraria;
    cout << "Digite a quantidade de vagas: ";
    cin >> c->qntVagas;
    cout << "Digite o codigo do curso: ";
    cin >> c->codigoCurso;
}

void listarAlunos(meuAluno vetA[], meuCurso vetC[], int totalA, int totalC){
    if (alu == 0){
        cout << "Nenhum aluno foi cadastrado.\n";
        return;
    }
    for(int i = 0; i < alu; i ++){ //percorre só os alunos já cadastrados, sem acessar posições vazias
        cout << "Nome: " << vetA[i].nomeAluno << endl;
        cout << "Idade: " << vetA[i].idadeAluno<< endl;
        cout << "Numero de matricula: " << vetA[i].matriculaAluno << endl;

        // Encontra o curso do aluo
        string nomeCurso = "Nao encontrado";
        for(int j = 0; j <= totalC; j++){
                if (vetA[i].codigoCurso == vetC[j].codigoCurso)
                   nomeCurso = vetC[j].nomeCurso;
        }

        cout << "Curso: " << nomeCurso << endl;
        cout << endl;


    }

}

void listarCidades(minhaCidade vet[]){
    if(cid == 0){
        cout << "Nenhuma cidade cadastrada." << endl;
        return;
    }
    for(int i = 0; i<cid; i++){
        cout << endl;
        cout << "Nome: " << vet->nomeCidade << endl;
        cout << "Pais: " << vet->nomePais << endl;
        cout << endl;
    }
}

void listarCursos( meuCurso vet[]){
    if (pos == 0) {
    cout << "Nenhum curso cadastrado.\n";
    return;
    }
    for(int i = 0; i<pos; i++){ //percorre só os cursos já cadastrados, sem acessar asd posições vazias
        cout << endl;
        cout << "Codigo: " << vet[i].codigoCurso << endl;
        cout << "Nome: " << vet[i].nomeCurso << endl;
        cout << "Carga horaria: " << vet[i].cargaHoraria << endl;
        cout << "Vagas: " << vet[i].qntVagas << endl;
        cout << endl;
    }

}

void adicionarCurso(meuCurso vet[], meuCurso c){
    if(pos < N)
        vet[pos++] = c; //adiciona um curso e aumenta o cotador automaticamente
    else
        cout << "Lista cheia. Curso nao adicionado." << endl;
}

bool codigoExiste(meuCurso vet[], int cod){
    for(int i = 0; i < pos; i ++){
        if(vet[i].codigoCurso == cod){
            return true;
        }

    }
        return false;


}

void buscarAlunos (meuAluno vetAlunos[], int totalAlunos){
    int cod;
    cout << "Digite o codigo do curso: ";
    cin >> cod;

    bool encontrou = false;

    for(int i = 0; i < totalAlunos; i ++){
        if(vetAlunos[i].codigoCurso == cod){
            encontrou = true;
            cout << "Nome: " << vetAlunos[i].nomeAluno << endl;
            cout << "Matricula: " << vetAlunos[i].matriculaAluno << endl;
            cout << "Idade: " << vetAlunos[i].idadeAluno << endl;
            cout << endl;
        }
    }

    if(!encontrou){
        cout << "Nenhum aluno encontrado para esse curso..." << endl;
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
    cout << "7 - para cadastrar uma cidade" << endl;
    cout << "8 - para listar cidades" << endl;
    cout << "9 - para salvar" << endl;
    cout << "10 - para carregar" << endl;
    cout << "11 - para sair" << endl;
}

void relatorioGeral(meuCurso vetCursos[], int totalCursos, meuAluno vetAlunos[], int totalAlunos) {
    if (totalCursos == 0) {
        cout << "Nenhum curso cadastrado.\n";
        return;
    }

    cout << "\n--- RELATORIO GERAL ---\n";

    for (int i = 0; i < totalCursos; i++) {
        int contador = 0;

        // percorre todos os aluos e conta os que estão esse curso
        for (int j = 0; j < totalAlunos; j++) {
            if (vetAlunos[j].codigoCurso == vetCursos[i].codigoCurso) {
                contador++;
            }
        }

        cout << "Curso: " << vetCursos[i].nomeCurso << endl;
        cout << "Codigo: " << vetCursos[i].codigoCurso << endl;
        cout << "Alunos matriculados: " << contador << endl;
        cout << "-----------------------------\n";
    }
}

void salvar(meuAluno vet[], meuCurso vetCu[], minhaCidade vetCi[], int n) {
    fstream meuArquivo;

    meuArquivo.open("matriculas.bin", ios::out | ios::binary);

    if(meuArquivo.is_open()) {
        meuArquivo.write((char *) vet, sizeof(meuAluno) * n);
        meuArquivo.write((char *) vetCu, sizeof(meuCurso) * n);
        meuArquivo.write((char *) vetCi, sizeof(minhaCidade) * n);
        meuArquivo.write((char *) &alu, sizeof(alu));
        meuArquivo.write((char *) &pos, sizeof(pos));
        meuArquivo.write((char *) &cid, sizeof(cid));
        meuArquivo.close();
        cout << "Informacoes salvas com sucesso!!\n";
    }
    else {
        cout << "Falha ao gravar informacoes.\n";
    }
}

void carregar(meuAluno vet[], meuCurso vetCu[], minhaCidade vetCi[], int n) {
    fstream meuArquivo;
    meuArquivo.open("matriculas.bin", ios::in | ios::binary);

    if(meuArquivo.is_open()) {
        meuArquivo.read((char *) vet, sizeof(meuAluno) * n);
        meuArquivo.read((char *) vetCu, sizeof(meuCurso) * n);
        meuArquivo.read((char *) vetCi, sizeof(minhaCidade) * n);
        meuArquivo.read((char *) &alu, sizeof(alu));
        meuArquivo.read((char *) &pos, sizeof(pos));
        meuArquivo.read((char *) &cid, sizeof(cid));
        meuArquivo.close();
        cout << "Informacoes carregadas com sucesso!!\n";
    } else {
        cout << "Falha ao carregar informacoes.\n";
    }
}

int main(){
    int opcao;
    meuCurso esteCurso;
    meuCurso vetorCursos[MAX];
    meuAluno esteAluno;
    meuAluno vetorAlunos[MAX];
    minhaCidade estaCidade;
    minhaCidade vetorCidades[MAX];

    mostrarMenu();
    cin >> opcao;

    while(opcao != 11){
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
               if (pos == 0){
                    cout << "Nenhum curso cadastrado. Cadastre um curso primeiro.\n";
                }   else if(alu < N){
                        cadastrarAluno(&vetorAlunos[alu], vetorCursos, pos);
                        alu++;
                }   else{
                    cout << "Limite de alunos atingido.\n";
                }
                break;
            case 3:
                listarCursos(vetorCursos);
                break;
            case 4:
                listarAlunos(vetorAlunos, vetorCursos, alu, pos);
                break;
            case 5:
                buscarAlunos(vetorAlunos, alu);
                break;
            case 6:
                relatorioGeral(vetorCursos, pos, vetorAlunos, alu);
                break;
            case 7:
                cadastrarCidade(&estaCidade);
                adicionarCidade(vetorCidades, estaCidade);
                break;
            case 8:
                listarCidades(vetorCidades);
            case 9:
                salvar(vetorAlunos, vetorCursos, vetorCidades, MAX);
                break;
            case 10:
                carregar(vetorAlunos, vetorCursos, vetorCidades, MAX);
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
