#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main ()
{
    char name[40]; //Dilonoume ton pinaka gia to onoma tou paikti, einai pinakas xarakthrwn 40 thesewn outws wste na ftanei gia tin apothikeusi enos onomatos
    int choice[100], number_of_rounds, i, player, cpu;//Dilwnoume pinakes gia tis epiloges xrhsth k ypologisti, epilegoume megalo megethos pinaka gia na
    int computer_choice[100]; //min exoume provlima me ti seira twn epanalhpsewn
    int playerwin, cpuwin, border; //Dilwsi metrhtwn nikwn kai oriou nikwn se periptwsi isopalias
    number_of_rounds=playerwin=cpuwin=border=0;//Arxikopoihsh metavlitwn gia na min exoume provlima mesa sth for

    for(i=0; i<100; i++) //Arxikopoihsh tou pinaka me midenikes times
    {
        choice[i]=0;
    }

    srand(time(NULL)); //Klhsh synarthshs gia paragwgi tyxaiwn arithmwn

    system("color a"); //Allagi xrwmatos grammatoseiras stin konsola
    printf("Give player name:\n"); //Zhteitai apo to xrhsth na dwsei to onoma tou
    gets(name); //Diavazetai o pinakas xarakthrwn pou periexei to onoma

    printf("...........................................................\n");

    printf("Player %s, Start!!!:\n", name); //To paixnidi ksekinaei gia ton epilegmeno xrhsth


    printf("Enter number of rounds:\n"); //Zhtame apo to xrhsth na eisagei ton arithmo twn gyrwn pou thelei na paiksei
    scanf("%d", &number_of_rounds);

    while(number_of_rounds<=0) //Kanoume elegxo arnhtikwn timwn
    {
    printf("Wrong input, enter again:");
    scanf("%d", &number_of_rounds);
    }


    for(i=0;i<number_of_rounds;i++) //Arxh tou paixnidiou apo ton 1o mexri to gyro pou epilegei o paikths os teleutaio
    {
    printf("\nRound :%d\n", i+1);
    printf("\nEnter your choice: 1 for rock, 2 for scissors, 3 for paper:");//Kaleitai o xrhsths na eisagei tin epilogi tou
    scanf("%d", &choice[i]);

    while(choice[i]<1 ||choice[i]>3) //elegxos gia lanthasmenes times
    {
        printf("Wrong input, try again:");
        scanf("%d", &choice[i]);
    }


    computer_choice[i] = rand() % 3 + 1; //paragontai tyxaioi arithmoi, isoi se arithmo me tis eisagwges xrhsth, gia ton ypologisth
                                         //xrhsimopoioume ypoloipo diairesis me to 3 gia na exoume apotelesmata apo 1 mexri 3


    printf("\nRock, Paper, Scissors 1...2...3 ! \n");

    //Ksekinaei o elegxos apotelesmatwn tou paixnidiou
    //Periptosi 1 - An kai oi 2 dialeksoun to idio. Edw prepei kai o gyros na epanalifthei giati exoume isopalia
    if(choice[i]==computer_choice[i])
    {
        printf("Draw,");
        if(choice[i]==1 && computer_choice[i]==1)//An kai oi 2 exoun epileksei 1, diladi petra
        {
            printf(" rock vs rock!\n");
            cpuwin++; //o metritis nikwn auksanetai kata 1 kai gia tous 2
            playerwin++;
            i--; //To i meiwnetai kata 1, opote ksanapaizetai o gyros
            printf("\n Repeating round...\n");
        }
        else if (choice[i]==2 && computer_choice[i]==2) //Omoiws otan kai oi 2 exoun epileksei 2
        {
            printf(" scissors vs scissors!\n");
            cpuwin++;
            playerwin++;
            i--;
            printf("\n Repeating round...\n");
        }
        else if (choice[i]==3 && computer_choice[i]==3) //Omoiws otan kai oi 2 exoun epileksei 3
        {
            printf(" paper vs paper!\n");
            cpuwin++;
            playerwin++;
            i--;
            printf("\n Repeating round...\n");
        }
    }
    else if (choice[i]>computer_choice[i]) // an o xrhsths exi epileksei megalytero arithmo apo ton ypologisti
    {
        if(choice[i]==3 && computer_choice[i]==1)
        {
            printf("You win, Paper VS Rock\n"); //de xreiazetai sxolia, grafoume edw ti ginetai
            playerwin++; //o metrhths nikwn tou xrhsth auksanetai kata 1
        }
        else if(choice[i]==3 && computer_choice[i]==2)
        {
            printf("You lose, Paper VS Scissors\n");//Omoia taktiki akoloutheitai kai stis epomenes periptoseis
            cpuwin++;
        }
        else if(choice[i]==2 && computer_choice[i]==1)
        {
            printf("You lose, Scissors VS Rock\n");
            cpuwin++;
        }

    }//end of else if (player>cpu)

    else if(choice[i]<computer_choice[i])
    {
        if(choice[i]==1 && computer_choice[i]==2)
        {
            printf("You win, Rock VS Scissors\n");
            playerwin++;
        }

        else if(choice[i]==1 && computer_choice[i]==3)
        {
            printf("You lose, Rock VS Paper\n");
            cpuwin++;
        }

        else if(choice[i]==2 && computer_choice[i]==3)
        {
            printf("You win, Scissors VS Paper\n");
            playerwin++;
        }

    }//end of last elseif

    }//end of for


    if(cpuwin>playerwin) //An o ypologistis exei perissoteres nikes apo ton paikth, kerdizei autos
    {
        printf("\nThe computer pwned you with a score of %d - %d, GAME OVER :(\n", cpuwin, playerwin);
    }
    else if(playerwin>cpuwin) //Alliws kerdizei o paikths
    {
        printf("\nEpic Win!!! Score: %d - %d!!! :)\n", playerwin, cpuwin);
    }
    else if(cpuwin==playerwin) //An meta apo olous tous gyrous exoume isopalia, prepei na epanalifthoun oi gyroi mexri na yparxei diafora nikwn 2 anamesa s epaikth /ypologisti
    {                          //Gia na apofygoume periplokes periptoseis, xrhsimopoioume apolyti timi gia ton arithmo twn nikwn
        printf("\nDrama on, we continue!!!\n");
        border=abs(cpuwin-playerwin);//Ypologismos arxika tis apolytis timis, pou einai 0 meta tin isopalia.
                                     //H apolyti timi ypologizetai me xrhsh ths synarthshs abs()

        do{ //do while, ksanapaikse to paixnidi mexri i apolyti timi na ginei 2
        //to paixnidi ksanaarxizei, auti ti fora me xrhsh metavlhtwn
        printf("\nEnter your choice: 1 for rock, 2 for scissors, 3 for paper:");
        scanf("%d", &player);


    while(player<1 || player>3)
    {
        printf("Wrong input, try again:");
        scanf("%d", &player);
    }


    cpu = rand() % 3 + 1;

    printf("\nRock, Paper, Scissors 1...2...3 ! \n");


    if(player==cpu)
    {
        printf("Draw,");
        if(player==1 && cpu==1)
        {
            printf(" rock vs rock!\n");
            cpuwin++;
            playerwin++;
            i--;
            printf("\n Repeating round...\n");
        }
        else if (player==2 && cpu==2)
        {
            printf(" scissors vs scissors!\n");
            cpuwin++;
            playerwin++;
            i--;
            printf("\n Repeating round...\n");
        }
        else if (player==3 && cpu==3)
        {
            printf(" paper vs paper!\n");
            cpuwin++;
            playerwin++;
            i--;
            printf("\n Repeating round...\n");
        }
    }
    else if (player>cpu)
    {
        if(player==3 && cpu==1)
        {
            printf("You win, Paper VS Rock\n");
            playerwin++;
        }
        else if(player ==3 && cpu==2)
        {
            printf("You lose, Paper VS Scissors\n");
            cpuwin++;
        }
        else if(player==2 && cpu==1)
        {
            printf("You lose, Scissors VS Rock\n");
            cpuwin++;
        }

    }//end of else if (player>cpu)

    else if(player<cpu)
    {
        if(player==1 && cpu==2)
        {
            printf("You win, Rock VS Scissors\n");
            playerwin++;
        }

        else if(player==1 && cpu==3)
        {
            printf("You lose, Rock VS Paper\n");
            cpuwin++;
        }

        else if(player==2 && cpu==3)
        {
            printf("You win, Scissors VS Paper\n");
            playerwin++;
        }


    }

        border=abs(cpuwin-playerwin);

        }while(border<2);


        if(cpuwin>playerwin) //Teliko apotelesma httas
        {
            printf("\nGaMe OvER :( Score---> Computer: %d - You: %d\n", cpuwin, playerwin);
        }
        else
        {
            printf("\nCoNgRaTuLaTiOns, you WON :) Score: ---> You: %d - Computer: %d\n", playerwin, cpuwin); //Teliko apotelesma nikis
        }
    }//end of last else if in case of final draw

    system("pause");
    return 0;
}
