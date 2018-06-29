#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#define TAM 12
#define ATR 5

int Ataque(int Racas[ATR], int Boss[4], int Armas[4], int opArmas, int morreu){
    int turno=1, fugas=0, dano, acao, roll, rollBoss;
    int i = 0;
    while((Boss[0]>0)&&(Racas[0]>0)){
        printf("\n\n\n=-=-=-=-=-=-TRUNO %i-=-=-=-=-=-=\n", turno);
        if(turno%2!=0){
            turno++;
            printf("\n _____________");
            printf("\n|1 - Atacar   |");
            printf("\n|2 - Fugir    |");
            printf("\n ¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
            scanf("%i", &acao);
            if(acao == 1){
                rollBoss = d20();
                int ataque = Racas[1];
              	int defesa = Boss[2] + rollBoss;

                if(((d20()*2)>Armas[opArmas]) && (opArmas <=4 )){
                    ataque += Armas[opArmas];
                    dano = ataque - defesa;
                }else{
                    dano = ataque - defesa;
                }

                if(dano>0){
                    if((opArmas > 4)||(d20()==Armas[opArmas])){
                        dano = ataque - defesa;
                        ataque *=2;
                    }
                    Boss[0] -= dano;
                }else{
                Racas[0] += dano;
                };
                printf("Dano : %i \n", dano);
                printf("\n------------------------\n");
                printf("Seu HP : %i \n", Racas[0]);
                printf("\n------------------------\n");
                printf("Hp do atacado : %i \n", Boss[0]);
                printf("Atk do Boss : %i \n", Boss[1]);
                printf("Def do Boss : %i \n", Boss[2]);
            }else if(acao == 2){
                printf("Voce não conseguiu fugir e foi morto, A Vitoria e somente dos Bravos");
                morreu += 1;
                break;
            }
        }else if(turno%2==0){
            turno++;
            printf("\n _____________");
            printf("\n|1 - Defender |");
            printf("\n|2 - Fugir    |");
            printf("\n ¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
            scanf("%i", &acao);
            if(acao ==1){
                roll = d20();
              	Sleep(roll*100);
              	rollBoss = d20();
                dano = (Boss[1] + roll) -( Racas[2] + rollBoss);
                if(dano>0){
                    if(roll == 20 ){
                        dano*=2;
                	}
               		Racas[0] -= dano;
                }else{
                    Boss[0] += dano;
                };
                printf("Dano : %i \n", dano);
                printf("\n------------------------\n");
                printf("Seu HP : %i \n", Racas[0]);
                printf("D20 : %i\n", roll);
                printf("\n------------------------\n");
                printf("Hp do Boss : %i \n", Boss[0]);
                printf("Atk do Boss : %i \n", Boss[1]);
                printf("Def do Boss : %i \n", Boss[2]);
                printf("D20 : %i\n", roll);
            }else if(acao == 2){
                printf("Voce não conseguiu fugir e foi morto, A Vitoria e somente dos Bravos");
                morreu += 1;
                break;
            }
        }
    }
    if(Racas[0]<0){
        morreu += 1;
    }
    return 0;
}

int d20(){
    int r;
    srand(time(NULL));
    r = 1+(rand()%20);
    return r;
}

int main()
{
    int Leao[3] = {50, 55, 10};
    int Troll[3]={80, 65, 15};
    int Grokdarr[3]={350, 80, 2};

    int Racas[ATR], opRaca, i, opClasse= 0, opArmas, inicial, morreu = 0;
    int Armas[4]={10,15,13,10};
    int vetor[10], busca;

    setlocale(LC_ALL, "Portuguese");
    printf("\n 1-Anão\n 2-Elfo \n 3-Dragonato \n 4-Humano : ");
    scanf("%i", &opRaca);

    if(opRaca == 1){
        Racas[0] = 75; //PONTOS DE VIDA
        Racas[1] = 30; //ATAQUE
        Racas[2] = 45; //DEFESA
        Racas[3] = 1; //TIPO DE RACA
    }else if(opRaca == 2){
        Racas[0] = 50; //PONTOS DE VIDA
        Racas[1] = 30; //ATAQUE
        Racas[2] = 70; //DEFESA
        Racas[3] = 2 ;//TIPO DE RACA
    }else if(opRaca == 3){
        Racas[0] = 40; //PONTOS DE VIDA
        Racas[1] = 75; //ATAQUE
        Racas[2] = 35; //DEFESA
        Racas[3] = 3 ;//TIPO DE RACA
    }else if(opRaca == 4){
        Racas[0] = 50; //PONTOS DE VIDA
        Racas[1] = 50; //ATAQUE
        Racas[2] = 50; //DEFESA
        Racas[3] = 4 ;//TIPO DE RACA
    }else{
        printf("Raca invalida!");
    }
    system("cls");
    printf("Pontos de Vida : %i\n", Racas[0]);
    printf("Ataque : %i\n", Racas[1]);
    printf("Defesa : %i\n", Racas[2]);
    printf("Sorte : %i\n", Racas[3]);
    printf("\n\n\n\n");
    system("cls");
    printf("ESCOLHA A ARMA QUE DESEJA USAR:\n");
    printf("\n 0- Espada\n 1 - Balestra\n 2- BanjoMágico\n 3- Lança \n 4 - Martelo\n");
    scanf("%i", &opArmas);
    for(i=0;i<10;i++){
        vetor[i]= d20();//vai atribuir à cada posição do vetor um valor aleatório entre 1 e 20
        printf("Carregando...");
        Sleep(d20() * 100);
        system("cls");
    }
    printf("Digite um valor aleatório entre 1 e 20. Se o valor existir dentro do vetor, você ganhará HP extra igual à posição do vetor em que este valor estava armazenado (mínimo 1, máximo 10)");
    scanf("%i", &busca);
    i=0;
    while((busca!=vetor[i])&&(i<10)){ //Faz a busca dentro do vetor
        i++;
    }
    if(i<10){ //caso o valor tenha sido encontrado
        i++;
        printf("\nO valor %i foi encontrado na posição %i do vetor. Você recebe um bônus de %i HP\n",busca,i,i);
        Racas[0]+=i;
    }else{
        printf("\nNão encontrado, sem bonus!\n");
    }
    inicial = Racas[0];
    system("pause");
    system("cls");
    printf("NÂO FUJA!!!");
    Sleep(800);
    system("cls");
    printf("Você é um mercenário na cidade de Feltres, a capital da mercenagem no continente.\n");
    printf("Uma vez por ano, mercenários de todos o continente vêm a Feltres para o grande \n");
    printf("evento conhecido como Arena da Metrópole. Este evento dura uma semana, e nele mercenários\n");
    printf("se tornam gladiadores em busca de ouro e glória. Alguns conseguem posições de prestígio\n");
    printf("em exércitos ou como membros de guardas reais, graças à constante presença de generais e\n");
    printf("nobres. Pela primeira vez, você decide se inscrever no evento. O recrutador te diz:\n\n");
    printf("\t-Bem vindo garoto. Primeira vez, não é? Bem vindo. Ou você sai daqui com glória ou sai daqui morto.\n\n");
    printf("É um grande risco a se correr. Mas a recompensa é valiosa. Você se inscreve de qualquer\n");
    printf("jeito. O evento começa na próxima semana, e você aproveita o tempo para treinar. \n");
    printf("Chega o grande dia. Você está junto com tantos outros como você. Um inspetor dá as instruções.\n");
    printf("\t-Vejo muita carne nova aqui. Vocês sabem que boa parte de vocês não vai sair viva. Mas aqueles\n");
    printf("que saírem vivos serão bem pagos. Mas lembrem-se: os fugitivos morrerão!\n\n");
    printf("Por ser sua primeira vez, você é escolhido para o combate de abertura contra um leão. Você entra\n");
    printf("na arena e encara a multidão que grita sedenta por sangue. É possível ver os camarotes onde estão\n");
    printf("nobres, generais e ricos comerciantes. Você empunha sua arma e olha para a jaula. O feroz leão é\n");
    printf("libertado, e te olha com cautela. Você é a presa e ele o predador. O leão avança para cima de você.\n");
    printf("É hora do combate\n");
    Ataque(Racas, Leao, Armas, opArmas, morreu);//chama função combate
    Racas[0] = inicial; //"healar" o personagem
    if(morreu == 0){
        printf("\n");
        system("pause");
        system("cls");
        printf("Você derrota o leão e é ovacionado pela multidão. O sangue do leão dá pinta a areia no chão na arena\n");
        printf("e os nobres em seus camarotes te olham impressionados com a sua habilidade. Saindo da arena,\n você é");
        printf("parabenizado pelo inspetor, que o convida para participar de um novo combate daqui dois dias.\n");
        printf("É tempo suficiente para se recuperar da luta de hoje e se preparar. Você aceita.\n");
        printf("Dois dias depois, você volta à arena. Seu combate será contra um oponente surpresa. Você entra na arena\n");
        printf("e encara a multidão novamente. Eles estão ansiosos para ver Hregnýmr, o matador de leões em ação mais \n");
        printf("uma vez. O anunciante diz: \n\n");
        printf("\t-SENHORAS E SENHORES, BEM-VINDOS AO TERCEIRO DIA DA ARENA DA METRÓPOLE! HOJE TEREMOS A LUTA DE HREGNÝMR\n");
        printf("\tCONTRA UM TROLL DA MONTANHA! SERÁ QUE ELE É CAPAZ DE VENCER?\n\n");
        printf("Os portões são abertos e o Troll é libertado. A monstruosa figura acelera em sua direção brandindo uma clava\n");
        printf("e grunhindo furiosamente. A multidão vibra. Você empunha sua arma.\n");
        Ataque(Racas, Troll, Armas, opArmas, morreu); //chama função combate
        Racas[0] = inicial;//"healar" o personagem
    }else{
        printf("VOCÊ MORREU!!");
    }
     if(morreu == 0){
        system("pause");
        system("cls");
        printf("Após um árduo combate, você derrota o enorme Troll, que cai estremecendo o chão e produzindo o estrondo. A\n");
        printf("grande maioria dos que lutam contra Trolls não sobrevivem aos primeiros três minutos de luta. Mas você \n");
        printf("prevaleceu. A multidão grita por Hregnýmr, o matador de trolls. Ao deixar a arena, você é abordado por \n");
        printf("um mensageiro:\n\n");
        printf("\t-Saudações, matador de Trolls. Venho em nome do Rei de Pythonia, Guido van Rossum. O rei se impressionou\n");
        printf("com suas habilidades, e deseja lhe fazer uma oferta: Uma generosa quantia em ouro e um cargo na Guarda Real\n");
        printf("de Pythonia. Contudo, para isso, você deverá derrotar o grande Campeão das três últimas edições da Arena da\n");
        printf("Metrópole, Grokdarr. Se aceitar, será arranjado para que o combate seja o encerramento do evento deste ano.\n\n");
        printf("Você conhece a fama de Grokdarr. Campeão invicto nas últimas três edições, ficou famoso por derrotar dez \n");
        printf("adversários de uma só vez. Você só consegue pensar como o rei na verdade deseja te ver morto. Contudo, a \n");
        printf("oferta é tentadora. Você diz:\n\n");
        printf("\t-Diga ao rei que aceito o desafio.\n\n");
        printf("Você passa os próximos dias se preparando e se recuperando da última luta.\n");
        printf("No último dia da Arena da Metrópole deste ano, você retorna à arena de Feltres. Nas últimas horas, várias\n");
        printf("batalhas foram travadas sobre essas areias. Chegou o seu momento: brilhar ou cair. Você e Grokdarr entram\n");
        printf("na arena por portões distindos e a multidão delira. Os ocupantes dos camarotes observam atentos. O \n");
        printf("anunciante diz:\n\n");
        printf("\t-SENHORAS E SENHORES, PARA A ÚLTIMA LUTA DESTE ANO, DAMOS A VOCÊS AQUILO QUE DESEJAVAM! DE UM LADO, O\n");
        printf("CAMPEÃO INVICTO DAS ÚLTIMAS EDIÇÕES: GROKDARR, DO REINO DE JAVASCRIPTION! DO OUTRO LADO, A SURPRESA \n");
        printf("DESTE ANO: HREGNÝMR, UM DOS POUCOS A SOBREVIVER AO DESAFIO DO TROLL!\n\n");
        printf("O grande Orc de dois metros se aproxima de você. Os gritos da multidão ecoam por toda a arena. Grokdarr \n");
        printf("o saúda batendo no próprio peito. Para aqueles que são saudados dessa forma, isso normalmente significa\n");
        printf("a própria morte. Não como provocação, mas um sinal de respeito de guerreiros Orcs àqueles oponentes que\n");
        printf("eles consideram dignos. Você saúda Grokdarr respeitosamente. Grokdarr levanta seu machado de guerra.\n");
        Ataque(Racas, Grokdarr, Armas, opArmas, morreu);//chama função combate
        Racas[0] = inicial; // "healar" o personagem
        }else{
        printf("VOCÊ MORREU!!");
    }
     if(morreu == 0){
        system("pause");
        system("cls");
        printf("Contrariando todas as expectativas, você vence Grokdarr. A multidão grita seu nome e o anunciante te\n");
        printf("declara como o novo campeão da Arena da Metrópole. Toda glória ao campeão!\nVocê saúda Grokdarr respeitosamente uma última vez.\n Como prometido, você se torna\n");
        printf("parte da Guarda Real Pythoniana e recebe a recompensa em ouro que lhe foi prometida.\n");
        printf("FIM\n Obrigado por jogar.");
    }else{
        printf("VOCÊ MORREU!!");
    }
    return 0;
