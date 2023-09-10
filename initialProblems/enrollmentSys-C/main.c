#include <stdio.h>

#define MAX 1000001 //numero maximo do codigo do aluno 

int main (void){

	int matriculas[MAX]; //vetor de matriculas, a posicao i representa o curso no qual
	//o aluno i esta inscrito (ex: aluno 2 se matricula no curso 1: matriculas[2] = 1)
	for(int i = 0; i < MAX; i++){
		matriculas[i] = 0; 
	}

	int n_cursos;
	scanf(" %d", &n_cursos);
	
	int cursos[n_cursos+1]; //vetor para armazenar a quantia de alunos em cada curso
	for(int i = 0; i < n_cursos; i++){
		int n_inscritos;
		scanf(" %d", &n_inscritos);
		for(int j = 0; j < n_inscritos; j++){
			int cod;
			scanf(" %d", &cod);
			if(matriculas[cod] == 0)
				matriculas[cod] = i+1; //matricula o aluno no curso
			else if(matriculas[cod] != i+1){
				matriculas[cod] = -1; //representa o aluno excluido de qualquer curso
			}
		}	
		cursos[i+1] = 0; //inicializamos cada elemento em 0
	}

	for(int i = 0; i < MAX; i++){
		if(matriculas[i] > 0)
			cursos[matriculas[i]] += 1; //soma um aluno ao curso atual
	}

	for(int i = 1; i <= n_cursos; i++){
		printf("%d ", cursos[i]);
	}
	
	return 0;
}
