#include <locale.h> 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define fyd 218,2 
#define PI 3.1415926536 
//fun��o interpola��o que ser� usada em angulo morros e valores   
float maior(float a,float b,float c,float d){ 
float x[4]={a,b,c,d}; 
int i,j; 
float aux,cresente; 
for(i=0;i<=5;i++){ 
for(j=i+1;j<=5;j++){ 
if(x[i]<x[j]){ 
aux=x[i]; 
x[i]=x[j]; 
x[j]=aux; 
} 
} 
} 
return x[0]; 
} 
float menor3(float a,float b,float c,float d){ 
float x[4]={a,b,c,d}; 
int i, j; 
float aux,cresente; 
for(i=0;i<=5;i++){ 
for(j=i+1;j<=5;j++){ 
if(x[i]>x[j]){ 
aux=x[i]; 
x[i]=x[j]; 
x[j]=aux; 
} 
} 
} 
return x[0]; 
} 
float interpolacao(float i1, float i2, float j1, float j2, float x){ 
float a, b, c, y; 
a=x-i1; 
b=i2-i1; 
c=j2-j1; 
y=(((c*a)/b) + j1); 
return y;                                        
} 
float arctg(float x, float y){ 
float r, o; 
r = y/x; 
o = atan(r)*180/PI; 
return o; 
} 
float barrahipo(float a, float b){ 
float c, d; 
a=a*100; 
c=pow(a,2)+pow(b,2); 
d=pow(c,1.0/2.0); 
return d; 
} 
float tabvent(int a, int b){ 
float X[4][15]={{1.06,1.04,1.01,0.94,0.92,0.89,0.88,0.86,0.82,0.79,0.76,0.73,0.74,0.72,0.67},{1.10,1.09,1.06,1.00,0.98,0.95,0.94,0.92,0.88,0.86,0.83,0.80,0.74,0.72,0.67},{1.13,1.12,1.09,1.04,1.02,0.99,0.98,0.96,0.93,0.90,0.88,0.84,0.79,0.76,0.72},{1.15,1.14,1.12,1.06,1.04,1.02,1.01,0.99,0.96,0.93,0.91,0.88,0.82,0.80,0.76}}; 
return X[a][b]; 
} 
float comont(float esfobarra,float ECOD,float FCOD,float inercia,float L,float base,float altura){ 
float x1,x2,x3,x4,x5,x6,xt; 
x1=esfobarra/(base*altura); 
//printf("esfobarra/(base*altura)=%5.5fMPa\n",x1); 
x2=(pow(PI,2)*ECOD*inercia)/(pow(L,2)); 
//printf("%f*%f*%f/%f=%5.5f\n",pow(PI,2),ECOD,inercia,pow(L,2),x2); 
x3=L/300; 
//printf("L/300=%5.5fmm\n",x3); 
x4=esfobarra*x3*(x2/(x2-esfobarra))*(base/2)/inercia; 
//printf("esfobarra*x3*(x2/(x2-esfobarra))*(base/2)/inerciamin=%5.5f\n",x4); 
x5=x1/FCOD; 
//printf("x1/FCOD=%.15f\n",x5); 
x6=x4/FCOD; 
//printf("x4/FCOD=%f\n",x6); 
xt=x5+x6; 
//printf("x5+x6=%f\n",xt); 
if(xt>=0){ 
return xt; 
} 
else{ 
return 2; 
} 
} 
float compressaodebarracomposta(float L, float EFEM,float esfobarracompressao,float inerciaefeticay,float inercia2, float base, float altura, float a1){ 
float x1,x2,x3,x4,x11,x12,x13,x14,xt;  
x1=L/300; 
x2=(pow(PI,2)*EFEM*inerciaefeticay)/(0.9*pow(L,2)*pow(10,6)); 
x3=(esfobarracompressao*x1*(x2/(x2-esfobarracompressao))); 
x4=inercia2/(base/2); 
x11=esfobarracompressao/(2*base*altura); 
x12=(x3*inercia2)/(inerciaefeticay*x4); 
x13=x3/(2*a1*base*altura); 
x14=1-(2*inercia2/inerciaefeticay); 
xt=x11+x12+x13*x14; 
return xt; 
} 
float pino(int i, int j){ 
float Pino[2][10]={{12.5,16,19,22,25,31,38,44,50,75},{1.68,1.52,1.41,1.33,1.27,1.19,1.14,1.1,1.07,1.0}}; 
return Pino[i][j]; 
} 
float embut90(float embut0, int j){ 
float xt; 
xt=embut0*0.25*pino(1,j); 
return xt; 
} 
float menor2(float t1,float t2){ 
int i,j; 
float x[2]={t1,t2},aux,xt;  
for(i=0;i<2;i++){ 
for(j=i+1;j<2;j++){ 
if(x[i]>x[j]){ 
aux=x[i]; 
x[i]=x[j]; 
x[j]=aux; 
} 
} 
}xt=x[0]; 
return xt; 
} 
float menor(float t1,float t2,float t3){ 
int i,j; 
float x[3]={t1,t2,t3},aux,xt;  
for(i=0;i<3;i++){ 
for(j=i+1;j<3;j++){ 
if(x[i]>x[j]){ 
aux=x[i]; 
x[i]=x[j]; 
x[j]=aux; 
} 
} 
} 
xt=x[0]; 
return xt; 
} 
float embutimento(float Fe0,float Fe90,float teta){ 
float Fteta,x1,x2; 
x1=sin(teta); 
x2=cos(teta); 
Fteta=(Fe0*Fe90)/(Fe0*pow(x1,2)+Fe90*pow(x2,2)); 
return Fteta; 
} 
float betas(float t,float dpino,float Fteta){ 
float beta,betaM,x; 
beta=t/pino(0,dpino); 
x=fyd/Fteta; 
betaM=1.25*sqrt(x); 
if(beta>betaM){ 
return 1; 
} 
else if(beta<=betaM){ 
return 2; 
} 
} 
float pinon(float n1){ 
float resto; 
int produto; 
produto=10*n1; 
resto=produto%10; 
//printf("R=%f,P=%d\n",resto,produto); 
if(n1>2){ 
if(resto<5){ 
n1=n1+0.5; 
return n1; 
} 
else{ 
n1=n1; 
return n1; 
} 
} 
else{ 
return 2; 
} 
} 
int main(){ 
setlocale(LC_ALL,"Portuguese"); 
system("color 70 "); 
int estilotrelica,x,n11,n21,n31,n41,n12,n22,n32,n42,coerencia,vaotrelica1,comprimentotrelica1,contadorvao,analisevao,mpm,rep,eixox,eixoy,mad,classedemadeira,telha,i,ibd,i1,u,v0,regiao,estado,grupo,relevo1,relevo2,categoria,largura1,largura2,de1,de2,de11,de22,linha1,linha2,coluna1,casex,coluna3,coluna4,espmaxmontante,j,areaterca,contadorterca,dw,mudancadem,L1,L2,L3,var1,var2,var3,var4,mo,dpino,d2,n,emb,u1,u2,Xind,f1,f2,f3,f4,co; 
float volumetotal[1000],volumefinal,Lcontra,volumecontra,pesoinicial,pesofinal,Maxpino,goldmad,goldtrat,goldtelha,areafinal,F1,F2,F3,F4,forca1,forca2,basecontra,alturacontra,vaotrelica3,comprimentotrelica2,Fe0,Fe90,ND,t,base2,base3,Fteta,beta,rvd1,teta,teta1,teta2,FCODn1,n1,n2,inercia,esbeltez,inerciamin,CSgo,esfobarra2,esfobarra1,altura,base,tensao,areatota,inerciaX,inerciaY,inercia1,inercia2,FCOD,FCOD1,area,altura1,base1,a1,inerciay,L,barra,l1,l2,b1,b2,m,m2,contador,aux,beta1,inerciaefeticay,areatotal,esbeltezefetiva,EFEM,ECOD,esfobarracompressao,x23,ECOD1,razaotrelica,alturatrelica,banzomax,razaoaltura,vaotrelica2,razaodovao,facy,a,b,c,d,KMOD,FVOD,densidade,s1,alturamorro,BMA,pedireito,distanciabasetopo,s106, s117, s145,s21,s22,s3,angulomorro,alturatrelicah1,vk0,vk90,pesotelha,PS,alturaestrutura,razaoce,razaod,angulotrelica,ceEF,ceGH,ceEG,ceFH,ceIJ,ceEF1,ceGH1,ceEG1,ceFH1,ceEF2,ceGH2,ceEG2,ceFH2,ceangulotrelica1,ceangulotrelica2,cpi90,cpi0,qk90,qk0,barras1,inerciatercaX,inerciatercaY,wtercaX,wtercaY,fcodterca,fvodterca,efemterca,momento1,tetasin,tetacos,tetaa,tetaacos,tetaasin,PS2,barraforcay,barraforcax,fventox,fventoy,R,razao,PS1,lterca,pesoterca,pesotelha1,pesoproprioterca,momentopropriocalculoterca,cortantepropriocalculoterca,momentoventocalculoterca,cortanteventocalculoterca,momentopessoacalculoterca,cortantepessoacalculoterca,momentofavoraveltercaX,momentofavoraveltercaY,momentodesfavoraveltercaX,momentodesfavoraveltercaY,cortantefavoraveltercaX,cortantefavoraveltercaY,cortantedesfavoraveltercaX,cortantedesfavoraveltercaY,momentotercaX,momentotercaY,cortantetercaX,cortantetercaY,tensaotercaNX,tensaotercaNY,verificacaotensaotercaNX,verificacaotensaotercaNY,tensaotercaTX,tensaotercaTY,razaoterca,betaM,establat1,establat2,flechapptercaX,flechapptercaY,flechapqtercaX,flechapqtercaY,flechatercaX,flechatercaY,volbi,basebi,alturabi,volbs,basebs,alturabs,volterca,pesomad,vold0,basedi,alturadi,volmo,basemo,alturamo,vold1,vold2,baseterca,alturaterca; 
float VX[1000],VY[1000],barraforcaz[300],forcavento[300],barraventoz[300],distaciasecoes[1000],barras[1000],PF[5],Lterca[1000],pesototal[1000],L11[1000],L22[1000],L33[1000],m1[1000],esfobarra[300],esfoliga1[1000],esfoliga[1000],Npino[1000]; 
float tabce1[3][5]={{-1,-0.4,-0.8,-0.6,15},{-0.4,-0.4,-0.7,-0.6,20},{0,-0.4,-0.7,-0.6,30}},tabce2[3][5]={{-1,-0.6,-0.8,-0.6,15},{-0.7,-0.5,-0.8,-0.6,20},{-0.2,-0.5,-0.8,-0.8,30}},tabce3[3][5]={{-0.8,-0.6,-0.8,-0.8,15},{-0.8,-0.6,-0.8,-0.8,20},{-1,-0.5,-0.8,-0.7,30}},tabBM[10]={6.0,8.8,12.3,15.9,19.5,23.1,26.7,30.3,34.0,37.6}; 
/*colocar os valores do vao e altura 
alem de definir o estilo da treli�a*/ 
FILE *arq; 
arq=fopen("Valores e dimensionamento da estrutura.txt","w"); 
printf("Qual estilo de treli�a?\n1-Howe\n2-Pratt\n"); 
printf("Estilo:"); 
scanf("%d",&estilotrelica); 
printf("\nQual tamanho do p� direito(m):"); 
scanf("%f",&pedireito); 
printf("\nDetermine os par�metros do v�o da treli�a(cm):"); 
scanf("%d",&vaotrelica1); 
printf("\nDetermine os par�metros do comprimento do galp�o(cm):"); 
scanf("%d",&comprimentotrelica1); 
coerencia=1; 
vaotrelica2=vaotrelica1/2; 
while (coerencia==1){ 
if(400>=(0.5*vaotrelica2)){ 
printf("\nDetermine os par�metros da altura da treli�a(cm), no m�ximo %.0f cm e m�nimo %.f cm:",0.5*vaotrelica2,0.286*vaotrelica2); 
scanf("%f",&alturatrelica); 
} 
else{ 
printf("\nDetermine os par�metros da altura da treli�a(cm), no m�ximo 400 cm e m�nimo %.f cm:",0.286*vaotrelica2); 
scanf("%f",&alturatrelica); 
} 
razaotrelica=alturatrelica/vaotrelica2; 
if(alturatrelica<=400){ 
if(razaotrelica>=0.286){     
if(razaotrelica<=0.5){ 
++coerencia; 
} 
else{ 
printf("\nDiminua a altura da treli�a para no m�ximo %.0f cm, pois a raz�o � de %.0f, uma raz�o que � maior de 0.25*v�o\n",0.5*vaotrelica2,razaotrelica); 
} 
} 
else{ 
printf("\nAumente a altura da treli�a para no m�nimo de %.0f cm, pois a raz�o � de %.3f, uma raz�o que � menor de 1/7*v�o\n",0.286*vaotrelica2,razaotrelica); 
} 
} 
else{ 
printf("\nDiminua a altura treli�a para um valor menor que 400 cm\n"); 
} 
} 
vaotrelica3=vaotrelica1; 
comprimentotrelica2=comprimentotrelica1; 
time_t rawtime; 
time (&rawtime); 
fprintf (arq,"%2.10s\n", ctime (&rawtime)); 
for(i=1;i<=100;i++) fprintf(arq,"*"); 
if(estilotrelica==1) fprintf(arq,"\nO estilo da geometria definido � Howe.\n"); 
else if(estilotrelica==2) fprintf(arq,"\nO estilo da geometria definido � Pratt.\n"); 
fprintf(arq,"Com os valores de:\nAltura da treli�a = %.2f m\nP� direito do Galp�o = %.2f m\nV�o da treli�a = %.2f m\nComprimento do galp�o = %.2f m\n",alturatrelica/100,pedireito,vaotrelica3/100,comprimentotrelica2/100); 
/*Escolha da telha de cobertura*/ 
printf("\nEscolha o tipo de telha que ser� utilizada:"); 
printf("\n1-L�minas de madeira revestida com alum�nio\n2-Alum�nio do tipo ondulada\n3-A�o do tipo trapezoidal\n4-Defina o peso e o espa�amento m�ximo das ter�as\n"); 
printf("Tipo:"); 
scanf("%d",&telha); 
switch (telha){ 
case 1: 
pesotelha=0.045;//4.5kgf/m� 
espmaxmontante=210; 
BMA=40; 
break; 
case 2: 
pesotelha=0.0151;//1.51kgf/m� 
espmaxmontante=175; 
BMA=40; 
break; 
case 3: 
pesotelha=0.0513;//5.13kgf/m� 
espmaxmontante=250; 
BMA=40; 
break; 
case 4: 
printf("Qual o peso por kgf/m� da telha:"); 
scanf("%f",&pesotelha); 
pesotelha=pesotelha/100; 
printf("Qual o espa�amento m�ximo das ter�as recomendado(cm):"); 
scanf("%d",&espmaxmontante); 
printf("Qual o espa�amento beiral m�ximo admiss�vel(cm):"); 
scanf("%d",&BMA); 
break; 
default: 
printf("\nTipo n�o escolhida\n"); 
break; 
} 
if(telha==1) fprintf(arq,"\nA Telha escolhida � de l�minas de madeira revestida com alum�nio onde obt�m os valores de:"); 
else if(telha==2) fprintf(arq,"A Telha escolhida � de alum�nio do tipo ondulada onde obt�m os valores de:"); 
else if(telha==3) fprintf(arq,"A Telha escolhida � de a�o do tipo trapezoidal onde obt�m os valores de:"); 
else if(telha==4) fprintf(arq,"A Telha escolhida � definida pelo usu�rio onde obt�m os valores de:"); 
//O if else acima faz a verifica��o das raz�es m�nimas e m�ximas da treli�a 
fprintf(arq,"\nPeso da telha = %.2f kgf/m�\nEspa�amento m�ximo entre ter�as = %.2f m\nBeiral M�ximo Admiss�vel = %.2f m\n",pesotelha*100,espmaxmontante/100.0,BMA/100.0); 
x=0; 
banzomax=pow(alturatrelica,2)+pow(vaotrelica1/2,2); 
banzomax=pow(banzomax,1.0/2.0); 
razaoaltura=(vaotrelica1*espmaxmontante)/(banzomax*2); 
contadorvao=1; 
for (analisevao=100;analisevao<=razaoaltura;analisevao++){ 
razaodovao=(vaotrelica1/2)%analisevao; 
if(razaodovao==0){ 
distaciasecoes[contadorvao]=analisevao; 
contadorvao++; 
} 
} 
alturatrelica=alturatrelica/100; 
/*Escolha da madeira*/ 
printf("\nEscolha o tipo Madeira e sua classe de resist�ncia conforme as op��es:"); 
printf("\n1-Con�fera\n2-Folhosa\n"); 
printf("Tipo:"); 
scanf("%d",&mad); 
KMOD=0.56; 
switch (mad){ 
case 1: 
printf("\nClasse da Con�fera:\n1-C20\n2-C25\n3-C30\n"); 
printf("Classe:"); 
scanf("%d",&classedemadeira); 
fprintf(arq,"\nA madeira � do tipo Con�fera de Classe de resist�ncia: "); 
switch (classedemadeira){ 
case 1: 
FCOD=KMOD*20*pow(10,6)/1.4; 
FVOD=KMOD*4*pow(10,6)/1.8; 
ECOD=KMOD*3500*pow(10,6); 
EFEM=KMOD*0.85*3500*pow(10,6); 
densidade=500; 
fprintf(arq,"C20\n"); 
break; 
case 2: 
FCOD=KMOD*25*pow(10,6)/1.4; 
FVOD=KMOD*5*pow(10,6)/1.8; 
ECOD=KMOD*8500*pow(10,6); 
EFEM=KMOD*0.85*8500*pow(10,6); 
densidade=550; 
fprintf(arq,"C25\n"); 
break; 
case 3: 
FCOD=KMOD*30*pow(10,6)/1.4; 
FVOD=KMOD*6*pow(10,6)/1.8; 
ECOD=KMOD*14500*pow(10,6); 
EFEM=KMOD*0.85*14500*pow(10,6); 
densidade=600; 
fprintf(arq,"C30\n"); 
break; 
default: 
printf("\nClasse n�o escolhida\n"); 
break; 
} 
break; 
case 2: 
printf("\nClasse da Folhosas:\n1-D20\n2-D30\n3-D40\n4-D50\n5-D60\n"); 
printf("Classe:"); 
scanf("%d",&classedemadeira); 
fprintf(arq,"\nA madeira � do tipo Dicotiled�neas de Classe de resist�ncia: "); 
switch (classedemadeira){ 
case 1: 
FCOD=KMOD*20*pow(10,6)/1.4; 
FVOD=KMOD*4*pow(10,6)/1.8; 
ECOD=KMOD*9500*pow(10,6); 
EFEM=KMOD*0.9*9500*pow(10,6); 
densidade=650; 
fprintf(arq,"D0\n"); 
break; 
case 2: 
FCOD=KMOD*30*pow(10,6)/1.4; 
FVOD=KMOD*5*pow(10,6)/1.8; 
ECOD=KMOD*14500*pow(10,6); 
EFEM=KMOD*0.9*14500*pow(10,6); 
densidade=800; 
fprintf(arq,"D30\n"); 
break; 
case 3: 
FCOD=KMOD*40*pow(10,6)/1.4; 
FVOD=KMOD*6*pow(10,6)/1.8; 
ECOD=KMOD*19500*pow(10,6); 
EFEM=KMOD*0.9*19500*pow(10,6); 
densidade=950; 
fprintf(arq,"D40\n"); 
break; 
case 4: 
FCOD=KMOD*50*pow(10,6)/1.4; 
FVOD=KMOD*7*pow(10,6)/1.8; 
ECOD=KMOD*22000*pow(10,6); 
EFEM=KMOD*0.9*22000*pow(10,6); 
densidade=970; 
fprintf(arq,"D50\n"); 
break; 
case 5: 
FCOD=KMOD*60*pow(10,6)/1.4; 
FVOD=KMOD*8*pow(10,6)/1.8; 
ECOD=KMOD*24500*pow(10,6); 
EFEM=KMOD*0.9*24500*pow(10,6); 
densidade=1000; 
fprintf(arq,"D60\n"); 
break; 
default: 
printf("\nClasse n�o escolhida\n"); 
break; 
} 
break; 
default: 
printf("\nTipo n�o escolhida\n"); 
break; 
} 
// o for Acima descreve o v�o que tem uma raz�o com resto 0 na divis�o 
printf("\nDist�ncia entre montantes poss�veis(cm):\n"); 
for(i=1;i<contadorvao;i++){ 
printf("%d - %.0f\n",i,distaciasecoes[i]); 
} 
//somente printa os valores obtidos no For 
printf("Qual:"); 
scanf("%d",&i); 
mpm=distaciasecoes[i]; 
//Obten��o da distancias entre montantes que o usu�rio pode definir 
rep=vaotrelica1/mpm; 
//quantas repeti��es o v�o tem da dist�ncia escolhida 
//Valores de X 
i=1; 
for (eixox=0;eixox<=rep;eixox++){ 
VX[i]=eixox*mpm/100.0; 
i++; 
} 
//pontos superiores a treli�a come�ando com ponto 1 = 0 indo at� x = 0 
i=1; 
for (eixox=rep+2;eixox<=rep*2;eixox++){ 
VX[eixox]=i*mpm/100.0; 
i++; 
} 
//Continuando os pontos partindo do banzo inferior "n" repeti��es + 2 que pula o 1 j� identificado e vai para o segundo diretamente 
//Valores de Y 
u=1; 
facy=rep/2; 
for (eixoy=0;eixoy<=facy;eixoy++){ 
VY[u]=eixoy*alturatrelica/facy; 
u++; 
} 
i=2; 
for (eixoy++;eixoy<=rep;eixoy++){ 
VY[u]=alturatrelica-VY[i]; 
i++; 
u++; 
} 
for (eixoy++;eixoy<=rep*2;eixoy++){ 
VY[u]=0; 
u++; 
} 
//Barras 
//HOWE 
//banzo superior 
for(i=1;i<=rep;i++){ 
a=mpm; 
b=alturatrelica*200/rep; 
c=pow(a,2)+pow(b,2); 
d=1/2.0; 
barras[i]=pow(c,d); 
} 
//banzo inferior = mpm 
for(i;i<=rep*2;i++) barras[i]=mpm; 
//Montante 
u=2; 
for(i;i<=rep*3-1;i++){ 
barras[i]=VY[u]*100; 
u++; 
} 
//Diagonais 
switch(estilotrelica){ 
//Howe 
case 1: 
u=2; 
for(i;i<=rep*3-2+facy;i++){ 
barras[i]=barrahipo(VY[u],mpm); 
u++; 
} 
u=rep/2+2; 
for(i;i<=rep*4-3;i++){ 
barras[i]=barrahipo(VY[u],mpm); 
u++; 
} 
break;         
//Pratt 
case 2: 
u=3; 
for(i;i<=rep*3-2+facy;i++){ 
barras[i]=barrahipo(VY[u],mpm); 
u++; 
} 
u=1+rep/2; 
for(i;i<=rep*4-3;i++){ 
barras[i]=barrahipo(VY[u],mpm); 
u++; 
} 
break; 
default: 
printf("\nEscolha Errada\n"); 
break; 
}     
/*Ventos*/ 
/*v0*/ 
printf("\nQual a regi�o do seu estado?"); 
printf("\n1 - Norte\n2 - Nordeste\n3 - Centro-Oeste\n4 - Sudeste\n5 - Sul\n"); 
printf("Regi�o:"); 
scanf("%d",&regiao); 
switch (regiao){//divis�o de regi�es 
case 1://norte 
printf("\nQual o estado da regi�o Norte?\n1 - Acre\n2 - Amap�\n3 - Amaz�nia\n4 - Para\n5 - Rond�nia\n6 - Roraima\n7 - Tocantins\n"); 
printf("Estado:"); 
scanf("%d",&estado); 
fprintf(arq,"\nA regi�o definida foi a Norte no estado"); 
if (estado == 1) fprintf(arq," do Acre.\n"); 
else if (estado == 2) fprintf(arq," do Amap�.\n"); 
else if (estado == 3) fprintf(arq," da Amaz�nia.\n"); 
else if (estado == 4) fprintf(arq," do Para.\n"); 
else if (estado == 5) fprintf(arq," da Rond�nia.\n"); 
else if (estado == 6) fprintf(arq," da Roraima.\n"); 
else if (estado == 7) fprintf(arq," de Tocantins.\n"); 
switch (estado){ 
case 1: 
v0 = 36; 
break; 
case 2: 
case 3: 
v0 = 30; 
break; 
case 4: 
v0 = 38; 
break; 
case 5: 
v0 = 49; 
break; 
case 6: 
v0 = 35; 
break; 
case 7: 
v0 = 33; 
break; 
default: 
printf("\nEstado n�o classificado\n"); 
break; 
} 
break; 
case 2://nordeste 
printf("\nQual o estado da regi�o Nordeste?\n1 - Alagoas\n2 - Bahia\n3 - Cear�\n4 - Maranh�o\n5 - Para�ba\n6 - Pernambuco\n7 - Piau�\n8 - Rio Grande do Norte\n9 - Sergipe\n"); 
printf("Estado:"); 
scanf("%d",&estado); 
fprintf(arq,"\nA regi�o definida foi a Nordeste e no estado"); 
if (estado == 1) fprintf(arq," de Alagoas.\n"); 
else if (estado == 2) fprintf(arq," da Bahia.\n"); 
else if (estado == 3) fprintf(arq," do Cear�.\n"); 
else if (estado == 4) fprintf(arq," do Maranh�o.\n"); 
else if (estado == 5) fprintf(arq," da Para�ba.\n"); 
else if (estado == 6) fprintf(arq," de Pernambuco.\n"); 
else if (estado == 7) fprintf(arq," do Piau�.\n"); 
else if (estado == 8) fprintf(arq," do Rio Grande do Norte.\n"); 
else if (estado == 9) fprintf(arq," de Sergipe.\n"); 
switch (estado){ 
case 1: 
case 3: 
case 5: 
case 8: 
case 9: 
v0 = 30; 
break; 
case 2: 
v0 = 40; 
break; 
case 4: 
v0 = 39; 
break; 
case 6: 
v0 = 35; 
break; 
case 7: 
v0 = 45; 
break; 
default: 
printf("\nEstado n�o classificado\n"); 
break; 
} 
break; 
case 3://Centro Oeste 
printf("\nQual o estado da regi�o Centro-Oeste?\n1 - Goi�s\n2 - Mato Grosso\n3 - Mato Grosso do Sul\n"); 
printf("Estado:"); 
scanf("%d",&estado); 
fprintf(arq,"\nA regi�o definida foi a Centro-Oeste e no estado"); 
if (estado == 1) fprintf(arq," de Goi�s.\n"); 
else if (estado == 2) fprintf(arq," do Mato Grosso.\n"); 
else if (estado == 3) fprintf(arq,"  do Mato Grosso do Sul.\n"); 
switch (estado){ 
case 1: 
case 2: 
v0 = 35; 
break; 
case 3: 
v0 = 50; 
break; 
default: 
printf("\nEstado n�o classificado\n"); 
break; 
} 
break; 
case 4://Suldeste 
printf("\nQual o estado da regi�o Sudeste?\n1 - Esp�rito Santo\n2 - Minas Gerais\n3 - Rio de Janeiro\n4 - S�o Paulo\n"); 
printf("Estado:"); 
scanf("%d",&estado); 
fprintf(arq,"\nA regi�o definida foi a sudeste e no estado"); 
if (estado == 1) fprintf(arq," do Esp�rito Santo.\n"); 
else if (estado == 2) fprintf(arq," de Minas Gerais.\n"); 
else if (estado == 3) fprintf(arq," do Rio de Janeiro.\n"); 
else if (estado == 4) fprintf(arq," de S�o Paulo.\n"); 
switch (estado){ 
case 1: 
v0 = 48; 
break; 
case 2: 
v0 = 46; 
break; 
case 3: 
v0 = 37; 
break; 
case 4: 
v0 = 45; 
break; 
default: 
printf("\nEstado n�o classificado\n"); 
break; 
} 
break; 
case 5://Sul 
printf("\nQual o estado da regi�o Sul?\n1 - Paran�\n2 - Rio Grande do Sul\n3 - Santa Catarina\n"); 
printf("Estado:"); 
scanf("%d",&estado); 
fprintf(arq,"\nA regi�o definida foi a Sul e no estado"); 
if (estado == 1) fprintf(arq," do Paran�.\n"); 
else if (estado == 2) fprintf(arq," do Rio Grande do sul.\n"); 
else if (estado == 3) fprintf(arq," de Santa Catarina.\n"); 
switch (estado){ 
case 1: 
case 2: 
v0 = 50; 
break; 
case 3: 
v0 = 45; 
break; 
default: 
printf("\nEstado n�o classificado\n"); 
break; 
} 
break; 
default: 
printf("\nRegi�o n�o classificada\n"); 
break; 
} 
/*S1*/ 
//par�metros iniciais 
printf("\nQual tipo dos terrenos a seguir ser� utilizado?\n"); 
printf("\n1 - Terreno plano\n2 - Fracamente acidentado\n3 - Encostas de morros e proximidades\n4 - Vales profundos protegido do vento\nTerreno:"); 
scanf("%d",&relevo1); 
fprintf(arq,"O relevo analisado � do tipo de "); 
if (relevo1 == 1) fprintf(arq," terreno plano.\n"); 
else if (relevo1 == 2) fprintf(arq," terreno fracamente acidentado.\n"); 
else if (relevo1 == 4) fprintf(arq," em vales profundos protegido do vento.\n"); 
switch (relevo1){ 
case 1: 
case 2: 
s1 = 1; 
break; 
case 3: 
printf("\nQual a altura do morro?\n"); 
scanf("%f",&alturamorro); 
alturatrelicah1=alturatrelica; 
printf("\nQual das alternativas abaixo corresponde a teorema a seguir:\n"); 
printf("\n1 - Esta na base do morro\n2 - Esta a uma distancia de %.2f do topo da encontra\n3 - Est� pr�ximo do topo da encontra\n",4*alturamorro); 
scanf("%d",&relevo2); 
if (relevo2 == 1) fprintf(arq," na base de morros.\n"); 
else if (relevo2 == 2) fprintf(arq,"  uma dist�ncia de %.2f do topo da encontra dos morros.\n",4*alturamorro); 
switch (relevo2) 
{ 
case 1: 
case 2: 
s1 = 1; 
break; 
case 3: 
printf("\nQual a dist�ncia horizontal da encosta para a base do morro para o topo:\n"); 
scanf("%f",&distanciabasetopo); 
fprintf(arq," pr�ximo ao topo do morro em uma dist�ncia inferior a %.f m.\n",4*alturamorro); 
angulomorro = arctg(distanciabasetopo,alturamorro); 
if(angulomorro <= 3) s1=1; 
else if(angulomorro >=6 && angulomorro <= 17) s1= 1+(2.5-(alturatrelicah1+pedireito)/alturamorro)*tan(angulomorro-3); 
else if(angulomorro >= 45) s1 = 1+(2.5-(alturatrelicah1+pedireito)/alturamorro)*0.31; 
else if(angulomorro >= 3 && angulomorro <=6) 
{ 
s106 = 1+(2.5-(alturatrelicah1+pedireito)/alturamorro)*tan(6); 
s1 = interpolacao(3, 6, 1, s106, angulomorro); 
} 
else if(angulomorro >=17 && angulomorro <=45) 
{ 
s117 = 1+(2.5-(alturatrelicah1+pedireito)/alturamorro)*tan(17); 
s145 = 1+(2.5-(alturatrelicah1+pedireito)/alturamorro)*0.31; 
s1 = interpolacao(17, 45, s117, s145, angulomorro); 
} 
break; 
case 4: 
s1 = 0.9; 
break; 
default: 
printf("\nN�o foi determinado corretamente o tipo do terreno\n"); 
break; 
} 
break; 
case 4: 
s1 = 0.9; 
break; 
default: 
printf("\nN�o tem esta alternativa\n"); 
} 
/*S2*/ 
largura1=vaotrelica1/100; 
largura2=comprimentotrelica1/100; 
//Classe A,B,C do v�o 
if(largura1<=20) de1=1; 
else if(largura1>20 && largura1<=50) de1=2; 
else de1=3; 
//Classe A,B,C do comprimento 
if(largura2<=20) de2=1; 
else if(largura2>20 && largura2<=50) de2=2; 
else de2=3; 
printf("\nQual das categorias enquadra o local do terreno:\n"); 
printf("Categoria 1:Locais perto de Mar calmo, Lagos e rios, P�ntanos sem vegeta��o\n"); 
printf("Categoria 2:Locais como zonas costeiras planas, p�ntanos com vegeta��o rala,\ncampos de avia��o, pradarias e charnecas ou fazendas sem sebes ou muros\n"); 
printf("Categoria 3:Granjas e casas de campos, fazendas com sebes, sub�rbios em m�dias\ndist�ncias dos centros com casa baixas e esparsas\n"); 
printf("Categoria 4:Zonas de parques e bosques com muitas �rvores, Cidades pequenas,\nsub�rbios em �reas urbanas, �reas industriais plena ou parcialmente constru�das\n"); 
printf("Categoria 5:Floresta com �rvores altas, Centro de cidades, complexo industriais\nbem desenvolvidos\n"); 
printf("Categoria:"); 
scanf("%d",&categoria); 
fprintf(arq,"A localidade da sua constru��o ser� pr�xima de "); 
if(categoria == 1) fprintf(arq,"de mar calmo, lagos e rios, p�ntanos sem vegeta��o.\n"); 
else if(categoria == 2) fprintf(arq,"zonas costeiras planas, p�ntanos com vegeta��o rala, campos de avia��o, pradarias e charnecas ou fazendas sem sebes ou muro.\n"); 
else if(categoria == 3) fprintf(arq,"granjas e casas de campos, fazendas com sebes, sub�rbios em m�dias dist�ncias dos centros com casa baixas e esparsas.\n"); 
else if(categoria == 4) fprintf(arq,"parques e bosques com muitas �rvores, Cidades pequenas, sub�rbios em �reas urbanas, �reas industriais plena ou parcialmente constru�das.\n"); 
else if(categoria == 5) fprintf(arq,"floresta com �rvores altas, Centro de cidades, complexo industriais bem desenvolvidos.\n"); 
switch (categoria){ 
case 1: 
de11=de1+0; 
de22=de2+0; 
switch (de1){ 
case 1: 
linha1=de11; 
break; 
case 2: 
linha1=de11; 
break; 
case 3: 
linha1=de11; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
switch (de2){ 
case 1: 
linha2=de22; 
break; 
case 2: 
linha2=de22; 
break; 
case 3: 
linha2=de22; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
break; 
case 2: 
de11=de1+3; 
de22=de2+3; 
switch (de1){ 
case 1: 
linha1=de11; 
break; 
case 2: 
linha1=de11; 
break; 
case 3: 
linha1=de11; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
switch (de2){ 
case 1: 
linha2=de22; 
break; 
case 2: 
linha2=de22; 
break; 
case 3: 
linha2=de22; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
break; 
case 3: 
de11=de1+6; 
de22=de2+6; 
switch (de1){ 
case 1: 
linha1=de11; 
break; 
case 2: 
linha1=de11; 
break; 
case 3: 
linha1=de11; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
switch (de2){ 
case 1: 
linha2=de22; 
break; 
case 2: 
linha2=de22; 
break; 
case 3: 
linha2=de22; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
break; 
case 4: 
de11=de1+9; 
de22=de2+9; 
switch (de1){ 
case 1: 
linha1=de11; 
break; 
case 2: 
linha1=de11; 
break; 
case 3: 
linha1=de11; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
switch (de2){ 
case 1: 
linha2=de22; 
break; 
case 2: 
linha2=de22; 
break; 
case 3: 
linha2=de22; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
break; 
case 5: 
de11=de1+12; 
de22=de2+12; 
switch (de1){ 
case 1: 
linha1=de11; 
break; 
case 2: 
linha1=de11; 
break; 
case 3: 
linha1=de11; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
switch (de2){ 
case 1: 
linha2=de22; 
break; 
case 2: 
linha2=de22; 
break; 
case 3: 
linha2=de22; 
break; 
default: 
printf("\nN�o escolhida\n"); 
break; 
} 
break; 
default: 
printf("\nTipo n�o escolhida\n"); 
break; 
} 
alturaestrutura=alturatrelicah1+pedireito; 
if(alturaestrutura<=5) coluna1=1; 
else if(alturaestrutura>5 && alturaestrutura<=10) coluna1=2; 
else if(alturaestrutura>10 && alturaestrutura<=15) coluna1=3; 
else if(alturaestrutura>15 && alturaestrutura<=20) coluna1=4; 
else printf("\nrecomenda-se outro tipo de galpao para esta altura\n"); 
s21=tabvent(coluna1-1,linha1-1); 
s22=tabvent(coluna1-1,linha2-1);//valor da tabvent [y-1][x-1] 
/*S3*/ 
printf("\nQual tipo de finalidade a edifica��o que vai ser constru�da:\n"); 
printf("\n1 - Quarteis de bombeiros, for�as de seguran�a, centrais de seguran�a\n2 - Hot�is e Resid�ncias\n3 - Dep�sitos e Constru��es Rurais\n4 - Veda��es de Vidro e telhas\n5 - Edifica��es tempor�rias dos tipos descrito nos itens 1 a 3\nTipo:"); 
scanf("%d",&grupo); 
fprintf(arq,"A finalidade do galp�o � para "); 
if(grupo == 1) fprintf(arq," quarteis de bombeiros, for�as de seguran�a, centrais de seguran�a.\n"); 
else if(grupo == 2) fprintf(arq,"hot�is e resid�ncias.\n"); 
else if(grupo == 3) fprintf(arq,"dep�sitos e constru��es rurais.\n"); 
else if(grupo == 4) fprintf(arq,"veda��es de Vidro e telha.\n"); 
else if(grupo == 5) fprintf(arq,"ser tempor�rio nos casos de centrais de seguran�a ou hot�is e resid�ncias ou constru��es rurais.\n"); 
switch (grupo){  
case 1: 
s3 = 1.1; 
break; 
case 2: 
s3 = 1; 
break; 
case 3: 
s3 = 0.95; 
break; 
case 4: 
s3 = 0.88; 
break; 
case 5: 
s3 = 0.83; 
break; 
} 
/*vk*/ 
//velocidade caracter�stica do vento m/s (v0=50 pois � o n�vel mais cr�tico no Brasil) 
vk0=v0*s1*s21*s3; 
vk90=v0*s1*s22*s3; 
//press�o din�mica do vento N/m� 
qk0=0.613*pow(vk0,2)/1000; 
qk90=0.613*pow(vk90,2)/1000; 
/*for�a efetiva*/ 
angulotrelica=arctg(vaotrelica1,alturatrelica); 
razaoce=pedireito/vaotrelica1; 
coluna3=0; 
coluna4=4; 
casex=0; 
//definir altura relativa e tamb�m busca do coeficiente de pre��o Ce para o angulo treli�a definido entre 15 e 30, pois s�o os �ngulos m�nimos q a treli�a howe permite 
if(razaoce<=0.5){ 
casex=1; 
if(angulotrelica == 15) coluna3=0; 
else if(angulotrelica == 20) coluna3=1; 
else if(angulotrelica < 20 && angulotrelica > 15) {coluna3=1;coluna4=0;} 
else if(angulotrelica < 30 && angulotrelica >20) {coluna3=2;coluna4=1;} 
} 
else if(0.5<razaoce && razaoce<=1.5){ 
casex=2; 
if(angulotrelica == 15) coluna3=0; 
else if(angulotrelica == 20) coluna3=1; 
else if(angulotrelica < 20 && angulotrelica > 15) {coluna3=1;coluna4=0;} 
else if(angulotrelica < 30 && angulotrelica >20) {coluna3=2;coluna4=1;} 
} 
else if(1.5<razaoce && razaoce<=6){ 
casex=3; 
if(angulotrelica == 15) coluna3=0; 
else if(angulotrelica == 20) coluna3=1; 
else if(angulotrelica < 20 && angulotrelica > 15) {coluna3=1,coluna4=0;} 
else if(angulotrelica < 30 && angulotrelica >20) {coluna3=2;coluna4=1;} 
} 
else{ 
printf("\ndimencao nao desejavel, altere a altura do galpao"); 
} 
if(coluna4==4){ 
switch (casex){ 
case 1: 
ceEF=tabce1[coluna3][0]; 
ceGH=tabce1[coluna3][1]; 
ceEG=tabce1[coluna3][2]; 
ceFH=tabce1[coluna3][3]; 
break; 
case 2: 
ceEF=tabce2[coluna3][0]; 
ceGH=tabce2[coluna3][1]; 
ceEG=tabce2[coluna3][2]; 
ceFH=tabce2[coluna3][3]; 
break; 
case 3: 
ceEF=tabce3[coluna3][0]; 
ceGH=tabce3[coluna3][1]; 
ceEG=tabce3[coluna3][2]; 
ceFH=tabce3[coluna3][3]; 
break; 
default: 
break; 
} 
} 
else{ 
switch (casex){ 
case 1: 
ceEF1=tabce1[coluna3][0]; 
ceGH1=tabce1[coluna3][1]; 
ceEG1=tabce1[coluna3][2]; 
ceFH1=tabce1[coluna3][3]; 
ceangulotrelica1=tabce1[coluna3][4]; 
ceEF2=tabce1[coluna4][0]; 
ceGH2=tabce1[coluna4][1]; 
ceEG2=tabce1[coluna4][2]; 
ceFH2=tabce1[coluna4][3]; 
ceangulotrelica2=tabce1[coluna4][4]; 
break; 
case 2: 
ceEF1=tabce2[coluna3][0]; 
ceGH1=tabce2[coluna3][1]; 
ceEG1=tabce2[coluna3][2]; 
ceFH1=tabce2[coluna3][3]; 
ceangulotrelica1=tabce2[coluna3][4]; 
ceEF2=tabce2[coluna4][0]; 
ceGH2=tabce2[coluna4][1]; 
ceEG2=tabce2[coluna4][2]; 
ceFH2=tabce2[coluna4][3]; 
ceangulotrelica2=tabce2[coluna4][4]; 
break; 
case 3: 
ceEF1=tabce3[coluna3][0]; 
ceGH1=tabce3[coluna3][1]; 
ceEG1=tabce3[coluna3][2]; 
ceFH1=tabce3[coluna3][3]; 
ceangulotrelica1=tabce3[coluna3][4]; 
ceEF2=tabce3[coluna4][0]; 
ceGH2=tabce3[coluna4][1]; 
ceEG2=tabce3[coluna4][2]; 
ceFH2=tabce3[coluna4][3]; 
ceangulotrelica2=tabce3[coluna4][4]; 
break; 
default: 
break; 
} 
ceEF = interpolacao(ceangulotrelica1, ceangulotrelica2, ceEF1, ceEF2, angulotrelica); 
ceGH = interpolacao(ceangulotrelica1, ceangulotrelica2, ceGH1, ceGH2, angulotrelica); 
ceEG = interpolacao(ceangulotrelica1, ceangulotrelica2, ceEG1, ceEG2, angulotrelica); 
ceFH = interpolacao(ceangulotrelica1, ceangulotrelica2, ceFH1, ceFH2, angulotrelica); 
} 
razaod=comprimentotrelica1/vaotrelica1; 
if(razaod == 1) ceIJ=ceFH; 
else if(razaod >= 2) ceIJ=-0.2; 
else ceIJ= interpolacao(1, 2, ceFH, -0.2, razaod); 
//Coeficiente de Press�o interna considerando duas faces opostas igualmente perme�veis; as outras faces imperme�veis 
cpi90=-0.3; 
cpi0=0.2; 
ceEF=(ceEF-cpi90)*qk90; 
ceGH=(ceGH-cpi90)*qk90; 
ceEG=(ceEG-cpi0)*qk0; 
ceFH=(ceFH-cpi0)*qk0; 
ceIJ=(ceIJ-cpi0)*qk0; 
/*Criar uma ordem crescente*/ 
PF[1]=ceEF; 
PF[2]=ceGH; 
PF[3]=ceEG; 
PF[4]=ceFH; 
PF[5]=ceIJ; 
for(i=1;i<=5;i++){ 
for(j=i+1;j<=5;j++){ 
if(PF[i]>PF[j]){ 
aux=PF[i]; 
PF[i]=PF[j]; 
PF[j]=aux; 
} 
} 
} 
if(fabs(PF[5])>fabs(PF[1])){ 
PS=PF[5]; 
} 
else{ 
PS=PF[1]; 
} 
//valores de vento no arquivo 
fprintf(arq,"\n"); 
for(i=1;i<=100;i++) fprintf(arq,"*"); 
fprintf(arq,"\nN�\t|\tEixo X(m)\t|\tEixo Y(m)\n"); 
for(i=1;i<=100;i++) fprintf(arq,"-"); 
fprintf(arq,"\n"); 
for(i=1;i<=rep*2;i++) fprintf(arq,"%d\t|\t%5.2f\t\t|\t%2.2f\n",i,VX[i],VY[i]); 
fprintf(arq,"\n");     
for(i=1;i<=100;i++) fprintf(arq,"*"); 
fprintf(arq,"\nBarra\t|\tDimens�o (cm)\n"); 
for(i=1;i<=100;i++) fprintf(arq,"-"); 
fprintf(arq,"\n"); 
for(i=1;i<=rep*4-3;i++) fprintf(arq,"%d\t|\t%8.2f\n",i,barras[i]); 
fprintf(arq,"\n"); 
for(i=1;i<=100;i++) fprintf(arq,"*"); 
fprintf(arq,"\nOs ventos que foram obtidos s�o:\n"); 
fprintf(arq,"Vento Inicial= %d m/s\nFator topogr�fico (S1)= %.2f\nFator de efeito combinado 0�(S2)= %.2f\nFator de efeito combinado 90�(S2)= %.2f\nFator Estat�stico (S3)= %.2f\n",v0,s1,s21,s22,s3); 
fprintf(arq,"Press�o do vento nas localidades da treli�a\n "); 
for(i=1;i<=31;i++)fprintf(arq,"-"); 
fprintf(arq," \n|\tE\t|\tF\t|\n "); 
for(i=1;i<=31;i++)fprintf(arq,"-"); 
fprintf(arq," \n|\tG\t|\tH\t|\n "); 
for(i=1;i<=31;i++)fprintf(arq,"-"); 
fprintf(arq," \n|\tI\t|\tJ\t|\n "); 
for(i=1;i<=31;i++)fprintf(arq,"-"); 
fprintf(arq," \nceEFI=%9.2f\nceGHJ=%9.2f\nceEG =%9.2f\nceFH =%9.2f\nceIJ =%9.2f\n",ceEF,ceGH,ceEG,ceFH,ceIJ); 
fprintf(arq,"For�a do vento= %f kN/m�\n",PS); 
do{ 
/*V�o da treli�a e verifica��o*/ 
//Equac�o �rea geom�trica 6*16 
printf("\nDetermine base da ter�a(cm)*Recomenda-se 6 cm*:"); 
scanf("%f",&baseterca); 
printf("\nDetermine altura da ter�a(cm)*Recomenda-se 16 cm*:"); 
scanf("%f",&alturaterca); 
areaterca=baseterca*alturaterca; 
//Equa��o do momento de inercia 
inerciatercaX=(baseterca*pow(alturaterca,3))/12; 
inerciatercaY=(alturaterca*pow(baseterca,3))/12; 
//Equa��o de inercia pela divis�o da base, nome n�o lembro 
wtercaX=(baseterca*pow(alturaterca,2))/6; 
wtercaY=(alturaterca*pow(baseterca,2))/6; 
u=1; 
for(i=100;i<=1000;i++){ 
R=comprimentotrelica1%i; 
if(R==0){ 
Lterca[u]=i; 
//printf("%d\t%.0f\n",u,Lterca[u]); 
u++; 
} 
} 
contadorterca=0; 
x=0; 
razao=vaotrelica2/2; 
razao=alturatrelica*100/razao; 
//printf("%f=%f/%f",razao,alturatrelica*100,vaotrelica2/2); 
angulotrelica=atan (razao); 
barras1=banzomax*2/rep; 
do{ //caso obtenha um valor maior que 1 isso quer dizer que alguma if de verifica��o deu problema ent�o para o sistema antes que de problema 
++x; 
lterca=Lterca[x]; 
fcodterca=FCOD/100000; 
fvodterca=FVOD/100000; 
efemterca=EFEM/100000; 
pesoterca=areaterca*densidade*lterca/(100*100*100*100); 
pesotelha1=pesotelha*barras1/100; 
pesoproprioterca=pesoterca+pesotelha; 
//momento e forca cortante peso pr�prio 
momentopropriocalculoterca=pesoproprioterca*pow(lterca,2)/8; 
cortantepropriocalculoterca=pesoproprioterca*lterca/2; 
//momento e forca cortante vento 
PS1=PS*lterca/100; 
momentoventocalculoterca=PS1*pow(lterca,2)/8; 
cortanteventocalculoterca=PS1*lterca/2; 
//momento e forca cortante da pessoa 
momentopessoacalculoterca=100*lterca/4;//carga centrada 
cortantepessoacalculoterca=50; 
//combina��o de esfor�os 
//momento 
//lembras de que o cosseno � em radianos ""cos(variable)"" 
momentofavoraveltercaX=0.9*(momentopropriocalculoterca)*cos(angulotrelica)+1.4*(0.75*momentoventocalculoterca)*cos(angulotrelica); 
momentofavoraveltercaY=0.9*(momentopropriocalculoterca)*sin(angulotrelica)+1.4*(0.75*momentoventocalculoterca)*sin(angulotrelica); 
momentodesfavoraveltercaX=1.4*(momentopropriocalculoterca)*cos(angulotrelica)+1.4*(momentopessoacalculoterca)*cos(angulotrelica); 
momentodesfavoraveltercaY=1.4*(momentopropriocalculoterca)*sin(angulotrelica)+1.4*(momentopessoacalculoterca)*sin(angulotrelica); 
cortantefavoraveltercaX=0.9*(cortantepropriocalculoterca)*cos(angulotrelica)+1.4*(0.75*cortanteventocalculoterca)*cos(angulotrelica); 
cortantefavoraveltercaY=0.9*(cortantepropriocalculoterca)*sin(angulotrelica)+1.4*(0.75*cortanteventocalculoterca)*sin(angulotrelica); 
cortantedesfavoraveltercaX=1.4*(cortantepropriocalculoterca)*cos(angulotrelica)+1.4*(cortantepessoacalculoterca)*cos(angulotrelica); 
cortantedesfavoraveltercaY=1.4*(cortantepropriocalculoterca)*sin(angulotrelica)+1.4*(cortantepessoacalculoterca)*sin(angulotrelica); 
//Analise do momento fletor critico 
if(fabs(momentofavoraveltercaX)<fabs(momentodesfavoraveltercaX)){ 
momentotercaX=momentodesfavoraveltercaX; 
momentotercaY=momentodesfavoraveltercaY; 
} 
else{ 
momentotercaX=momentofavoraveltercaX; 
momentotercaY=momentofavoraveltercaY; 
} 
//Analise da forca cortante critica 
if(fabs(cortantefavoraveltercaX)<fabs(cortantedesfavoraveltercaX)){ 
cortantetercaX=cortantedesfavoraveltercaX; 
cortantetercaY=cortantedesfavoraveltercaY; 
} 
else{ 
cortantetercaX=cortantefavoraveltercaX; 
cortantetercaY=cortantefavoraveltercaY; 
} 
//printf("cortantetercaX=%.3f\ncortantetercaY=%.3f\nmomentotercaY=%.3f\nmomentotercaX=%.3f\n",cortantetercaX,cortantetercaY,momentotercaX,momentotercaY); 
//verificac�o das tensoes normais 
// realizar para o eixo X e Y 
tensaotercaNX=momentotercaX/wtercaX; 
tensaotercaNY=momentotercaY/wtercaY; 
verificacaotensaotercaNX=tensaotercaNX/fcodterca; 
verificacaotensaotercaNY=tensaotercaNY/fcodterca; 
if((verificacaotensaotercaNX+0.5*verificacaotensaotercaNY)>=1){ 
contadorterca=1; 
printf("N�o passou na verifica��o porque o tens�es normais em Nx+0.5*Ny>1, recomenda-se aumentar a altura para elevar o comprimento da ter�a\n"); 
} 
else if((0.5*verificacaotensaotercaNX+verificacaotensaotercaNY)>=1){ 
contadorterca=2; 
printf("N�o passou na verifica��o porque o tens�es normais em 0.5*Nx+Ny>1, recomenda-se aumentar a base para elevar o comprimento da ter�a\n"); 
} 
//onde o Km � sempre = 0,5 pois se trata de madeira 
//Verificac�o das tens�es tangenciais 
tensaotercaTX=(cortantetercaX*3)/(2*baseterca*alturaterca); 
tensaotercaTY=(cortantetercaY*3)/(2*baseterca*alturaterca); 
if(tensaotercaTX>=fvodterca){ 
contadorterca=3; 
printf("N�o passou na verifica��o porque as tens�es tangenciais em Tx pois obteve um valor maior que resist�ncia ao cisalhamento, recomenda-se a elevar a �rea da se��o para obter valores maiores de comprimento\n"); 
} 
else if(tensaotercaTY>=fvodterca){ 
contadorterca=4; 
printf("N�o passou na verifica��o porque as tens�es tangenciais em Ty pois obteve um valor maior que resist�ncia ao cisalhamento, recomenda-se a elevar a �rea da se��o para obter valores maiores de comprimento\n"); 
} 
// reaverificacaotensaoNXlizar para X e Y 
//Verificar a estabilidade lateral 
razaoterca=alturaterca/baseterca; 
for(i=1;i<=10;i++){ 
if(i<=razaoterca && razaoterca<=i+1){ 
betaM=interpolacao(i+1, i, tabBM[i], tabBM[i+1], razaoterca);/*Interpolac�o*/ 
} 
} 
establat1=lterca/baseterca; 
establat2=(efemterca)/(0.9*betaM*fcodterca); 
if(establat1>=establat2){ 
contadorterca=5; 
printf("N�o passou na verifica��o por causa da Estabilidade Lateral, talvez aumentando sua base obtenha valores maiores de comprimento\n"); 
} 
/*Verificar se a betaM tem valor em rela��o a tabela, mas pode se considerar que a dimens�es da ter�a sempre tenha valores de 16x6 o bm = 2,67 assim obt�m valor de 11,14 para ele 
Verifica��o da flecha considera o valor da flecha somente para as for�as relacionadas com a pessoa pois o a constante para o vento �=0 
flecha do peso pr�prio*/ 
flechapptercaX=(5*pesoproprioterca*sin(angulotrelica)*pow(lterca,4)/(384*efemterca*inerciatercaY)); 
flechapptercaY=(5*pesoproprioterca*cos(angulotrelica)*pow(lterca,4)/(384*efemterca*inerciatercaX)); 
//flecha da pessoa 
flechapqtercaX=(100*sin(angulotrelica)*pow(lterca,3)/(48*efemterca*inerciatercaY)); 
flechapqtercaY=(100*cos(angulotrelica)*pow(lterca,3)/(48*efemterca*inerciatercaX)); 
flechatercaX=flechapptercaX+0.4*flechapqtercaX; 
flechatercaY=flechapptercaY+0.4*flechapqtercaY; 
if(flechatercaX>=lterca/200){ 
contadorterca=6; 
printf("N�o passou na verifica��o na flecha X, elevar a base para conseguir valores maiores de comprimento\n"); 
} 
else if(flechatercaY>=lterca/200){ 
contadorterca=7; 
printf("N�o passou na verifica��o a flecha Y, elevar a altura para conseguir valores maiores de comprimento\n"); 
} 
}while(contadorterca==0); 
x--; 
contadorterca=x; 
lterca=Lterca[contadorterca]; 
}while(lterca==0); 
x++; 
fprintf(arq,"\nUm comprimento da ter�a de %.f cm para uma se��o de base %.f cm e altura %.f cm. ",Lterca[x],baseterca,alturaterca); 
if(contadorterca==1) fprintf(arq,"N�o passa na verifica��o porque as tens�es normais em Nx+0.5*Ny>1, recomenda-se aumentar a altura para elevar o comprimento da ter�a.\n"); 
else if(contadorterca==2) fprintf(arq,"N�o passa na verifica��o porque as tens�es normais em 0.5*Nx+Ny>1, recomenda-se aumentar a base para elevar o comprimento da ter�a.\n"); 
else if(contadorterca==3) fprintf(arq,"N�o passa na verifica��o porque as tens�es tangenciais em Tx pois obteve um valor maior que resist�ncia ao cisalhamento, recomenda-se a elevar a area da se��o para obter valores maiores de comprimento.\n"); 
else if(contadorterca==4) fprintf(arq,"N�o passa na verifica��o porque as tens�es tangenciais em Ty pois obteve um valor maior que resist�ncia ao cisalhamento, recomenda-se a elevar a �rea da se��o para obter valores maiores de comprimento.\n"); 
else if(contadorterca==5) fprintf(arq,"N�o passa na verifica��o por causa da Estabilidade Lateral, talvez aumentando a base obtenha valores maiores de comprimento.\n"); 
else if(contadorterca==6) fprintf(arq,"N�o passa na verifica��o na flecha X, elevar a base para conseguir valores maiores de comprimento.\n"); 
else if(contadorterca==7) fprintf(arq,"N�o passa na verifica��o a flecha Y, elevar a altura para conseguir valores maiores de comprimento.\n"); 
fprintf(arq,"\nCom isso se adota o comprimento da ter�a � de %.f cm para uma se��o de base %.f cm e altura %.f cm.\n",lterca,baseterca,alturaterca); 
/*Fim*/ 
printf("\n\n O tamanho do comprimento nas an�lises � de %.2f cm, para uma geometria de base= %.f cm e altura= %.f cm.\n ",lterca,baseterca,alturaterca); 
printf("\nDetermine base dos banzos de se��o dupla(cm)*Recomenda-se 3 cm*:"); 
scanf("%f",&basebi); 
printf("\nDetermine altura dos banzos de se��o dupla(cm)*Recomenda-se 12 cm*:"); 
scanf("%f",&alturabi); 
printf("\nDetermine base do montante simples(cm)*Recomenda-se 3 cm*:"); 
scanf("%f",&basemo); 
printf("\nDetermine altura do montante simples(cm)*Recomenda-se 12 cm*:"); 
scanf("%f",&alturamo); 
printf("\nDetermine base da diagonal de se��o dupla(cm)*Recomenda-se 3 cm*:"); 
scanf("%f",&basedi); 
printf("\nDetermine altura da diagonal de se��o dupla(cm)*Recomenda-se 12 cm*:"); 
scanf("%f",&alturadi); 
lterca=lterca/100.0;         
basebi=basebi/100.0; 
basebs=basebi; 
basemo=basemo/100.0; 
basedi=basedi/100.0; 
alturabi=alturabi/100.0; 
alturabs=alturabi; 
alturamo=alturamo/100.0; 
alturadi=alturadi/100.0; 
baseterca=baseterca/100.0; 
alturaterca=alturaterca/100.0; 
system("cls"); 
  
//----------------------------------------------------------------------------------------------------------- 
do 
{ 
//area1 = rep+1 
//volume 
//duplo banzos 
volbi=mpm/100*basebi*alturabi; 
volbs=barras[1]/100*basebs*alturabs; 
volterca=lterca*baseterca*alturaterca; 
//peso 
pesomad=(volbi+volbs+volterca)*densidade; 
pesotelha1=pesotelha*((barras[1]/2)+BMA)*lterca; 
pesototal[1]=(pesomad+pesotelha1)*1.03; 
u=rep+1; 
pesototal[u]=pesototal[1]; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
  
//area 2 = n� = rep 
//volume 
if(rep>2) 
{ 
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
vold0=barras[rep*3]/100*basedi*alturadi;//base 6*12 
volmo=barras[rep*2+1]/100*basemo*alturamo; 
volterca=lterca*baseterca*alturaterca; 
  
pesomad=(volbi+volbs+volterca+volmo+vold0)*densidade; 
pesotelha1=pesotelha*barras[1]*lterca; 
pesototal[2]=(pesomad+pesotelha1)*1.03; 
pesototal[rep]=pesototal[2]; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
} 
//area 3 at� area (rep/2) = rep-1 a rep/2+2 
if(rep>4) 
{ 
u=rep-1; 
x=rep*3; 
for(i=3;i<=rep/2;i++) 
{ 
  
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
vold1=barras[x]/100*basedi*alturadi;//base 6*12 
vold2=barras[x+1]/100*basedi*alturadi; 
volmo=barras[u]/100*basemo*alturamo; 
volterca=lterca*baseterca*alturaterca; 
  
pesomad=(volbi+volbs+volterca+volmo+vold1+vold2)*densidade; 
pesotelha1=pesotelha*barras[1]*lterca; 
pesototal[i]=(pesomad+pesotelha1)*1.03; 
pesototal[u]=pesototal[i]; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
x++; 
u--; 
} 
} 
//area rep/2+1 
  
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
u=rep*3-2+facy; 
vold0=2*barras[u]/100*basedi*alturadi;//base 6*12 
volmo=barras[rep*3-1]/100*basemo*alturamo; 
volterca=2*lterca*baseterca*alturaterca; 
  
pesomad=(volbi+volbs+volterca+volmo+vold1+vold2)*densidade; 
pesotelha1=pesotelha*barras[1]*lterca; 
i=rep/2+1; 
pesototal[i]=(pesomad+pesotelha1)*1.03; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
pesoinicial=0; 
for(i=1;i<=rep+1;i++) 
{ 
pesototal[i]=pesototal[i]/100; 
//printf("peso %d - %f kn\n",i,pesototal[i]); 
pesoinicial=pesoinicial+pesototal[i]; 
} 
system("pause"); 
system("cls"); 
switch(estilotrelica){ 
case 1: 
/*Howe analise das barras*/ 
//momento 
momento1=0; 
for(i=2;i<=rep+1;i++){ 
momento1=momento1+pesototal[i]*VX[i]; 
//printf("\npeso %d - %.3f - %.3f kn\n",i,VX[i],pesototal[i]); 
} 
i--; 
forca1=momento1/(VX[i]); 
//printf("%.3f=%.3f/%.3f      %d",forca1,momento1,VX[i],i); 
n11=rep; 
n21=2*rep; 
n31=3*rep-1; 
n41=4*rep-2; 
n12=1; 
n22=rep+1; 
n32=2*rep+1; 
n42=3*rep-1; 
barraforcay=-forca1+pesototal[n11]; 
barraforcax=barraforcay*(VX[n22]-VX[n21])/(VY[n11]-VY[n22]); 
barraforcaz[n11]=pow(barraforcax,2)+pow(barraforcay,2); 
/*fazer uma analise de if e else*/ 
barraforcaz[n11]=pow(barraforcaz[n11],1.0/2.0); 
barraforcaz[n11]=-barraforcaz[n11]; 
barraforcaz[n21]=-barraforcax; 
//printf("\n%f=%d\n",barraforcaz[n11],n11); 
barraforcaz[n31]=0; 
/*Parte 1*/ 
n=0; 
teta=VY[2]*100/mpm; 
//printf("\nteta=%f-VY=%f-mpm=%d\n",teta,VY[2],mpm); 
teta=atan(teta); 
tetacos=cos(teta); 
tetasin=sin(teta); 
//printf("\nteta=%f-tetasin=%f-tetacos=%f\n",teta,tetasin,tetacos); 
do{ 
i1=n11; 
n11=--n11; 
n21=--n21; 
n31=--n31; 
n41=--n41; 
momento1=0; 
//printf("\n%d-%d-%d-%d",n11,n21,n31,n41); 
for(i=n11;i<=rep+1;i++) momento1=momento1+pesototal[i]*(VX[i]-VX[n11]); 
i--; 
barraforcaz[n11]=((forca1*(VX[n11]-VX[i]))+momento1)/(tetacos*VY[n11]); 
//printf("\n%f=%d  %d",barraforcaz[n11],n11,i1); 
/*Parte 2*/ 
momento1=0; 
for(i=i1;i>=1;i--){ 
momento1=momento1+pesototal[i]*(VX[i1]-VX[i]); 
} 
--i; 
barraforcaz[n21]=((forca1*(VX[i1]-VX[i]))-momento1)/VY[i1]; 
//printf("\n%f=%d",barraforcaz[n21],n21); 
/*Parte 3*/ 
tetaa=VY[i1]*100/mpm; 
tetaa=atan(tetaa); 
tetaacos=cos(tetaa); 
tetaasin=sin(tetaa); 
barraforcaz[n41]=((barraforcaz[i1]*tetacos)-(barraforcaz[n11]*tetacos))/tetaacos; 
//printf("\n%f=%d",barraforcaz[n41],n41); 
/*Parte 4*/ 
barraforcaz[n31]=-barraforcaz[n41]*tetaasin; 
//printf("\n%f=%d",barraforcaz[n31],n31); 
n++; 
}while(n11!=rep/2+1); 
barraforcaz[n31]=barraforcaz[n31]*2; 
//printf("\n%f=%d",barraforcaz[n31],n31); 
/*VENTO*/ 
lterca=Lterca[contadorterca]/100.0; 
teta=VY[2]*100/mpm; 
//printf("\nteta=%f-VY=%f-mpm=%d\n",teta,VY[2],mpm); 
teta=atan(teta); 
tetacos=cos(teta); 
tetasin=sin(teta);         
//printf("\n\n\n%f\n\n\n",PS); 
PS1=PS*lterca; 
//printf("\n\n\n%f\n\n\n",PS1); 
//forcavento[X][Y] 
for(i=1;i<=rep+1;i++){ 
if(i==1){ 
PS2=PS1*(BMA/100+(mpm/(200*tetacos))); 
forcavento[i]=PS2*tetasin; 
} 
else if(i==rep+1){ 
PS2=PS1*(BMA/100+(mpm/(200*tetacos))); 
forcavento[i]=PS2*tetasin; 
} 
else if(i==rep/2+1){ 
PS2=PS1*mpm/(tetacos*100); 
forcavento[i]=2*PS2*tetasin; 
} 
else if(i<=rep/2){ 
PS2=PS1*mpm/(tetacos*100); 
forcavento[i]=PS2*tetasin; 
} 
else{ 
PS2=PS1*mpm/(tetacos*100); 
forcavento[i]=PS2*tetasin; 
} 
//printf("\npeso %d - %.3f kn\n",i,forcavento[i]); 
} 
//momento 
momento1=0; 
for(i=2;i<=rep+1;i++){ 
momento1=momento1+forcavento[i]*VX[i]; 
//printf("\npeso %d - %.3f - %.3f kn\n",i,VX[i],forcavento[i]); 
} 
i--; 
forca1=-momento1/(VX[i]); 
//printf("%.3f=%.3f/%.3f\t%d",forca1,momento1,VX[i],i); 
n11=rep; 
n21=2*rep; 
n31=3*rep-1; 
n41=4*rep-2; 
n12=1; 
n22=rep+1; 
n32=2*rep+1; 
n42=3*rep; 
barraforcay=forca1-pesototal[n11]; 
//printf("\n%f=%d\n",barraforcay,n11); 
barraforcax=barraforcay*(VX[n22]-VX[n11])/(VY[n11]-VY[n22]); 
barraventoz[n11]=pow(barraforcax,2)+pow(barraforcay,2); 
/*fazer uma analise de if e else*/ 
barraventoz[n11]=pow(barraventoz[n11],1.0/2.0); 
barraventoz[n11]=barraventoz[n11]; 
barraventoz[n21]=-barraforcax; 
//printf("\n%f=%d\n",barraventoz[n11],n11); 
//printf("\n%f=%d\n",barraventoz[n21],n21); 
barraventoz[n31]=0; 
//printf("\n%f=%d\n",barraventoz[n31],n31); 
/*Parte 1*/ 
n=0; 
teta=VY[2]*100/mpm; 
//printf("\nteta=%f-VY=%f-mpm=%d\n",teta,VY[2],mpm); 
teta=atan(teta); 
tetacos=cos(teta); 
tetasin=sin(teta); 
//printf("\nteta=%f-tetasin=%f-tetacos=%f\n",teta,tetasin,tetacos); 
do{ 
i1=n11; 
n11=--n11; 
n21=--n21; 
n31=--n31; 
n41=--n41; 
momento1=0; 
//printf("\n%d-%d-%d-%d",n11,n21,n31,n41); 
for(i=n11;i<=rep+1;i++){ 
momento1=momento1+forcavento[i]*(VX[i]-VX[n11]); 
//printf("\n%f,%f, %f\n",momento1,forcavento[i],(VX[i]-VX[n11])); 
} 
i--; 
barraventoz[n11]=((forca1*(VX[i]-VX[n11]))+momento1)/(tetacos*VY[n11]); 
//printf("\n%f=%d",barraventoz[n11],n11); 
/*Parte 2*/ 
momento1=0; 
for(i=i1;i>=1;i--){ 
momento1=momento1+forcavento[i]*(VX[i1]-VX[i]); 
} 
--i; 
barraventoz[n21]=-((forca1*(VX[i1]-VX[i]))+momento1)/VY[i1]; 
//printf("\n%f=%d",barraventoz[n21],n21); 
/*Parte 3*/ 
tetaa=VY[i1]*100/mpm; 
tetaa=atan(tetaa); 
tetaacos=cos(tetaa); 
tetaasin=sin(tetaa); 
barraventoz[n41]=((barraventoz[i1]*tetacos)-(barraventoz[n11]*tetacos))/tetaacos; 
//printf("\n%f=%d",barraventoz[n41],n41); 
/*Parte 4*/ 
barraventoz[n31]=-barraventoz[n41]*tetaasin; 
//printf("\n%f=%d",barraventoz[n31],n31); 
n++; 
}while(n11!=rep/2+1); 
barraventoz[n31]=barraventoz[n31]*2; 
//printf("\n%f=%d",barraventoz[n31],n31); 
break; 
case 2: 
//momento 
momento1=0; 
for(i=2;i<=rep+1;i++){ 
momento1=momento1+pesototal[i]*VX[i]; 
} 
i--; 
forca1=momento1/(VX[i]); 
n11=rep; 
n21=2*rep; 
n31=3*rep-1; 
n41=4*rep-2; 
n12=1; 
n22=rep+1; 
n32=2*rep+1; 
n42=3*rep; 
barraforcay=-forca1+pesototal[n22]; 
barraforcax=barraforcay*(VX[n11]-VX[n22])/(VY[n11]-VY[n22]); 
barraforcaz[n11]=pow(barraforcax,2)+pow(barraforcay,2); 
/*fazer uma analise de if e else*/ 
barraforcaz[n11]=pow(barraforcaz[n11],1.0/2.0); 
barraforcaz[n11]=-barraforcaz[n11]; 
barraforcaz[n21]=barraforcax; 
barraforcaz[n31]=-pesototal[n11]; 
barraforcaz[n32]=barraforcaz[n31]; 
/*Parte 1*/ 
n=rep/2; 
i=n11; 
n11=--n11; 
barraforcaz[n11]=barraforcaz[i]; 
teta=VY[2]*100/mpm; 
teta=atan(teta); 
tetacos=cos(teta); 
tetasin=sin(teta); 
do{ 
i1=n11; 
n11=--n11; 
n21=--n21; 
n31=--n31; 
n41=--n41; 
momento1=0; 
//printf("\n%d-%d-%d-%d",n11,n21,n31,n41); 
tetaa=VY[i1]*100/mpm; 
tetaa=atan(tetaa); 
tetaacos=cos(tetaa); 
tetaasin=sin(tetaa); 
i=n31+1; 
barraforcaz[n41]=-barraforcaz[i]/tetaasin; 
//printf("\n%f=%d    Diagonal",barraforcaz[n41],n41); 
//Diagonal Calculada 
i=n21+1; 
barraforcaz[n21]=(-barraforcaz[n41]*tetaacos+barraforcaz[i]); 
//printf("\n%f=%d    Banzo Inferior",barraforcaz[n21],n21); 
//Banzo inFerior calculado 
/*Parte 2*/ 
momento1=0; 
for(i=i1;i>=1;i--) momento1=momento1+pesototal[i]*(VX[i1]-VX[i]); 
--i; 
barraforcaz[n11]=-((forca1*(VX[i1]-VX[i]))-momento1)/(VY[i1]*tetacos); 
//printf("\n%f=%d    Banzo Superior",barraforcaz[n11],n11); 
//Banzo Superior 
/*Parte 3*/ 
/*Parte 4*/ 
i=n11+1; 
barraforcaz[n31]=barraforcaz[n11]*tetasin-pesototal[i1]-barraforcaz[i]*tetasin-barraforcaz[n41]*tetaasin; 
//printf("\n%f=%d    Montante",barraforcaz[n31],n31); 
}while(n11 != n); 
barraforcaz[n31]=barraforcaz[n31]-barraforcaz[n31]; 
/*VENTO*/ 
lterca=Lterca[contadorterca]/100.0; 
teta=VY[2]*100/mpm; 
teta=atan(teta); 
tetacos=cos(teta); 
tetasin=sin(teta);         
PS1=PS*lterca; 
//forcavento[X][Y] 
for(i=1;i<=rep+1;i++){ 
forcavento[i]=-1; 
if(i==1){ 
PS2=PS1*(BMA/100+(mpm/(200*tetacos))); 
forcavento[i]=PS2*tetasin; 
} 
else if(i==rep+1){ 
PS2=PS1*(BMA/100+(mpm/(200*tetacos))); 
forcavento[i]=PS2*tetasin; 
} 
else if(i==rep/2+1){ 
PS2=PS1*mpm/(tetacos*100); 
forcavento[i]=2*PS2*tetasin; 
} 
else if(i<=rep/2){ 
PS2=PS1*mpm/(tetacos*100); 
forcavento[i]=PS2*tetasin; 
} 
else{ 
PS2=PS1*mpm/(tetacos*100); 
forcavento[i]=PS2*tetasin; 
} 
} 
forcavento[5]=-2; 
//momento 
momento1=0; 
for(i=2;i<=rep+1;i++){ 
momento1=momento1+forcavento[i]*VX[i]; 
//printf("\npeso %d - %.3f - %.3f kn\n",i,VX[i],forcavento[i]); 
} 
i--; 
forca1=momento1/(VX[i]); 
//printf("%.3f=%.3f/%.3f      %d",forca1,momento1,VX[i],i); 
n11=rep; 
n21=2*rep; 
n31=3*rep-1; 
n41=4*rep-2; 
n12=1; 
n22=rep+1; 
n32=2*rep+1; 
n42=3*rep; 
barraforcay=-forca1+forcavento[n22]; 
barraforcax=barraforcay*(VX[n11]-VX[n22])/(VY[n11]-VY[n22]); 
barraventoz[n11]=pow(barraforcax,2)+pow(barraforcay,2); 
/*fazer uma analise de if e else*/ 
barraventoz[n11]=pow(barraventoz[n11],1.0/2.0); 
barraventoz[n11]=barraventoz[n11]; 
//printf("\n%f=%d\n",barraventoz[n11],n11); 
barraventoz[n21]=barraforcax; 
//printf("\n%f=%d\n",barraventoz[n21],n21); 
barraventoz[n31]=-forcavento[n11]; 
/*Parte 1*/ 
n=rep/2; 
i=n11; 
n11=--n11; 
barraventoz[n11]=barraventoz[i]; 
teta=VY[2]*100/mpm; 
teta=atan(teta); 
tetacos=cos(teta); 
tetasin=sin(teta); 
do{ 
i1=n11; 
n11=--n11; 
n21=--n21; 
n31=--n31; 
n41=--n41; 
momento1=0; 
//printf("\n%d-%d-%d-%d",n11,n21,n31,n41); 
tetaa=VY[i1]*100/mpm; 
tetaa=atan(tetaa); 
tetaacos=cos(tetaa); 
tetaasin=sin(tetaa); 
i=n31+1; 
barraventoz[n41]=-barraventoz[i]/tetaasin; 
//printf("\n%f=%d    Diagonal",barraventoz[n41],n41); 
//Diagonal Calculada 
i=n21+1; 
barraventoz[n21]=(-barraventoz[n41]*tetaacos+barraventoz[i]); 
//printf("\n%f=%d    Banzo Inferior",barraventoz[n21],n21); 
//Banzo inFerior calculado 
/*Parte 2*/ 
momento1=0; 
for(i=i1;i>=1;i--){ 
momento1=momento1+forcavento[i]*(VX[i1]-VX[i]); 
//printf("%f\n",momento1); 
} 
--i; 
barraventoz[n11]=-((forca1*(VX[i1]-VX[i]))-momento1)/(VY[i1]*tetacos); 
//printf("\n%f=%d    Banzo Superior",barraventoz[n11],n11); 
//Banzo Superior 
/*Parte 3*/ 
/*Parte 4*/ 
i=n11+1; 
barraventoz[n31]=barraventoz[n11]*tetasin-forcavento[i1]-barraventoz[i]*tetasin-barraventoz[n41]*tetaasin; 
//printf("\n%f=%d    Montante",barraventoz[n31],n31); 
//printf("\n%d=%d=%d=%d=%d",n31,n11,i1,i,n41); 
}while(n11 != n); 
barraventoz[n31]=barraventoz[n31]*0; 
//printf("\n%f=%d=%d",barraventoz[n31],n31);         
default: 
break; 
} 
n11=rep; 
n21=2*rep; 
n31=3*rep-1; 
n41=4*rep-3; 
n12=1; 
n22=rep+1; 
n32=2*rep+1; 
n42=3*rep; 
//Otimizar???? 
for(i=1;i<=rep/2;++i){ 
barraforcaz[i]=barraforcaz[n11]; 
barraventoz[i]=barraventoz[n11]; 
barraforcaz[n22]=barraforcaz[n21]; 
barraventoz[n22]=barraventoz[n21]; 
barraforcaz[n32]=barraforcaz[n31]; 
barraventoz[n32]=barraventoz[n31]; 
barraforcaz[n42]=barraforcaz[n41]; 
barraventoz[n42]=barraventoz[n41]; 
n11=--n11; 
n21=--n21; 
n31=--n31; 
n41=--n41; 
n22=++n22; 
n32=++n32; 
n42=++n42; 
} 
/*                    */ 
fprintf(arq,"\n"); 
fprintf(arq,"\nN�\t|\tFor�a vento(kN)\n"); 
for(i=1;i<=100;i++) fprintf(arq,"-"); 
fprintf(arq,"\n"); 
for(i=1;i<=rep+1;i++) fprintf(arq,"%d\t|\t%7.4f\n",i,forcavento[i]); 
for(i=1;i<=100;i++) fprintf(arq,"-"); 
fprintf(arq,"\n"); 
for(i=1;i<=100;i++) fprintf(arq,"*"); 
/*                    */ 
fprintf(arq,"\n"); 
fprintf(arq,"\nBarra\t|\tPeso(kN)\t\t|\tVento(kN)\n"); 
for(i=1;i<=100;i++) fprintf(arq,"-"); 
fprintf(arq,"\n"); 
for(i=1;i<=4*rep-3;i++) fprintf(arq,"%d\t|\t%8.4f\t\t|\t%8.4f\n",i,barraforcaz[i],barraventoz[i]); 
for(i=1;i<=100;i++) fprintf(arq,"-"); 
fprintf(arq,"\n"); 
for(i=1;i<=100;i++) fprintf(arq,"*"); 
/*                    */ 
system("pause"); 
system("cls"); 
for(i=1;i<=4*rep-3;++i){ 
esfobarra[i]=0.9*barraforcaz[i]+1.4*0.75*barraventoz[i]; 
//printf("Esfor�o Barra %3.d - %.3f=0.9*%.3f+1.4*0.75*%f\n",i,esfobarra[i],barraforcaz[i],barraventoz[i]); 
} 
for(i=1;i<=4*rep-3;++i){ 
esfoliga[i]=0.9*barraforcaz[i]+1.4*barraventoz[i]; 
//printf("Esfor�o para liga��o na barra %3.d - %.3f=0.9*%.3f+1.4*%f\n",i,esfoliga[i],barraforcaz[i],barraventoz[i]); 
} 
basebi=basebi*1000; 
basebs=basebi; 
basemo=basemo*1000; 
basedi=basedi*1000; 
alturabi=alturabi*1000; 
alturabs=alturabi; 
alturamo=alturamo*1000; 
alturadi=alturadi*1000; 
FCOD1=FCOD/pow(10,6); 
L=Lterca[contadorterca]*10; 
ECOD1=ECOD/pow(10,6); 
for(i=1;i<=4*rep-3;i++){ 
if(i>2*rep && i<3*rep){ 
mo=0; 
do{ 
if(esfobarra[i]>=0)    { 
//printf("%d",i); 
esfobarra1=esfobarra[i]*1000; 
tensao=esfobarra1/(basemo*alturamo); 
if(tensao<=FCOD1){ 
mo++; 
//printf("Tens�o- %f - %f\n",tensao,FCOD1); 
} 
else if(basemo>(alturamo-10)){ 
alturamo=alturamo+10; 
//printf("New alturamo %f - %f\n",alturamo, basemo); 
} 
else{ 
basemo=basemo+10; 
//printf("New Base %f - %f\n",basemo,alturamo); 
} 
} 
else{ 
//printf("%d",i); 
esfobarra1=-esfobarra[i]*1000; 
inerciaX=basemo*pow(alturamo,3)/12; 
inerciaY=alturamo*pow(basemo,3)/12; 
if(inerciaX<inerciaY){ 
inercia=inerciaX; 
} 
else{ 
inercia=inerciaY; 
} 
inerciamin=sqrt(inercia/(basemo*alturamo)); 
esbeltez=L/inerciamin; 
//printf("Inercia min - %f=%f/%f\tEsbeltez - %f\n",inerciamin,inercia,(basemo*alturamo),esbeltez); 
if(esbeltez<40){ 
tensao=esfobarra1/(basemo*alturamo); 
if(tensao<=FCOD1){ 
mo++; 
//printf("\nTens�o- %f - %f\n",tensao,FCOD1); 
} 
else if(basemo>(alturamo-10)){ 
alturamo=alturamo+10; 
//printf("New alturamo %f - %f\n",alturamo, basemo); 
} 
else{ 
basemo=basemo+10; 
//printf("New Base %f - %f\n",basemo,alturamo); 
} 
} 
else if(40<=esbeltez && 80>esbeltez){ 
CSgo=comont(esfobarra1,ECOD1,FCOD1,inercia,L,basemo,alturamo); 
//printf("CSgo=%5.5f\nND=%5.5f\nECOD=%5.5f\nFCOD1%5.5f\nINERCIA=%5.5f\nL=%5.5f\nBASE=%5.5f\nAltura=%5.5f\n",CSgo,esfobarra1,ECOD1,FCOD1,inerciamin,L,basemo,alturamo); 
if(CSgo<=1){ 
//printf("\n\t\t%d\n%.4f<1.0000\n",i,CSgo); 
mo++; 
//printf("\n"); 
} 
else if(basemo>(alturamo-10)){ 
alturamo=alturamo+10; 
//printf("New alturamo %f - %f  CSgo=%5.5f\n",alturamo, basemo,CSgo); 
} 
else{ 
basemo=basemo+10; 
//printf("New Base %f - %f  CSgo=%5.5f\n",basemo,alturamo,CSgo); 
} 
} 
else if(80<=esbeltez && 140>esbeltez){ 
CSgo=comont(esfobarra1,ECOD1,FCOD1,inercia,L,basemo,alturamo); 
//printf("CSgo=%5.5f\nND=%5.5f\nECOD=%5.5f\nFCOD1%5.5f\nINERCIA=%5.5f\nL=%5.5f\nBASE=%5.5f\nAltura=%5.5f\n",CSgo,esfobarra1,ECOD1,FCOD1,inerciamin,L,basemo,alturamo); 
if(CSgo<=1){ 
//printf("\n\t\t%d\n%.4f<1.0000\n",i,CSgo); 
mo++; 
} 
else if(basemo>(alturamo-10)){ 
alturamo=alturamo+10; 
//printf("New alturamo %f - %f  CSgo=%5.5f\n",alturamo, basemo,CSgo); 
} 
else{ 
basemo=basemo+10; 
//printf("New Base %f - %f  CSgo=%5.5f\n",basemo,alturamo,CSgo); 
} 
} 
else{ 
if(basemo>(alturamo-10)) 
{ 
alturamo=alturamo+10; 
//printf("New alturamo %f - %f Esbeltez\n",alturamo, basemo); 
} 
else{ 
basemo=basemo+10; 
//printf("New Base %f - %f Esbeltez\n",basemo,alturamo); 
} 
} 
} 
}while(mo==0); 
} 
} 
  
for(i=1;i<=4*rep-3;i++){ 
if(i<=2*rep || i>=3*rep){ 
do{ 
dw=0; 
if(i<=2*rep){ 
altura=alturabi; 
base=basebi; 
base2=basemo; 
//printf("\n\n%d\n\n\taltura bi=%f,base bi= %f,altura mo = %f, basemo =%f\n\n\n\n\n",i,alturabi,basebi,alturamo,basemo); 
} 
else{ 
altura=alturadi; 
base=basedi; 
base2=basemo+basebi*2; 
//printf("\n\n%d\n\n\taltura di=%f,base di= %f,base 2 =%f\n\n\n\n\n",i,alturadi,basedi,base2); 
} 
  
//tra��o na barra 
if(esfobarra[i]>=0){ 
tensao=(esfobarra[i]*1000)/(2*altura*base); 
if(tensao<=FCOD1){ 
dw++; 
//printf("Altura -%.2f\nTens�o - %.2f < %.2f FCOD\n",altura,tensao,FCOD1); 
} 
else if(base>((altura/4.0)-10)){ 
altura=altura+10; 
//printf("Nova Altura -%.2f\n",altura); 
} 
else{ 
base=base+10; 
//printf("Nova base -%.2f\n",base); 
} 
} 
//compress�o em barras duplas 
else{ 
esfobarra1=-esfobarra[i]*1000; 
area=base*altura; 
inercia1=(base*pow(altura,3))/12; 
inercia2=(altura*pow(base,3))/12; 
inerciaX=2*inercia1; 
if((3*base)<=base2){ 
base=10+base; 
//printf("Base -%.2f\n ",base,base*3,base2); 
} 
else{     
a1=base/2+base2/2; 
inerciay=2*inercia2+2*area*(pow(a1,2)); 
mudancadem=1; 
l1=L/20; 
l2=L/10; 
b1=base*9; 
b2=base*18; 
ibd=1; 
//printf("%.f\t%.f\t%.f\t%.f\t%.f\t\n",L,l1,l2,b1,b2); 
for(L3=l1;L3<=l2;L3++){ 
var1=L-L3; 
//L1 
for(L1=b1;L1<=b2;L1++){ 
var2=var1%L1; 
var3=L1%50; 
var4=L3%10; 
if(var2==0&&var3==0&&var4==0){ 
//tem que guardar os valores para que eles n�o se percam; 
m1[ibd]=var1/L1; 
L33[ibd]=L3; 
L11[ibd]=L1; 
//printf("L1=%.f L3=%.f m=%.f\t%d\n",L11[ibd],L33[ibd],m1[ibd],ibd); 
ibd++; 
//printf("%d\n\n\n",L); 
} 
} 
} 
contador=ibd-1; 
//testar o menor m 
for(ibd=1;ibd<=contador;ibd++) 
{ 
for(j=ibd+1;j<=contador;j++) 
{ 
if(m1[ibd]<m1[j]) 
{ 
aux=m1[ibd]; 
m1[ibd]=m1[j]; 
m1[j]=aux; 
aux=L33[ibd]; 
L33[ibd]=L33[j]; 
L33[j]=aux; 
aux=L11[ibd]; 
L11[ibd]=L11[j]; 
L11[j]=aux; 
} 
} 
} 
m=1; 
if(L3>=1.5*base2) 
{ 
L2=L3; 
//printf("L2=%d   -   L3=%d\n",L2,L3); 
} 
else 
{ 
L2=1.5*base2; 
while((L2%10)!=0) 
{ 
L2++; 
} 
//printf("L2=%d      -      base2-%d\n",L2,base2); 
} 
mudancadem=1; 
do 
{ 
beta1=(inercia2*pow(m1[mudancadem],2)/(inercia2*pow(m1[mudancadem],2)+1.25*inerciay)); 
m2=m1[mudancadem]; 
//printf("%.2f=(%.2f*%.1f^2)/(%.2f*%.2f^2+1.25*%.2f)\n",beta1,inercia2,m2,inercia2,m2,inerciay); 
inerciaefeticay=beta1*inerciay; 
//printf("%.2f-%.2f\n",beta1,inerciaefeticay); 
//printf("%.2f>%.2f\n",inerciaX,inerciaefeticay); 
if(m2==0) 
{ 
if(base>altura/4-10) 
{ 
altura=altura+10; 
m=0; 
//printf("Nova Altura -%.2f\n",altura); 
} 
else 
{ 
m=0; 
base=base+10; 
//printf("Nova base -%.2f\n",base); 
} 
} 
else{ 
//printf("%.2f=(%.2f*%.1f^2)/(%.2f*%.2f^2+1.25*%.2f)\n",beta1,inercia2,m2,inercia2,m2,inerciay); 
inerciaefeticay=beta1*inerciay; 
//printf("%.2f-%.2f\n",beta1,inerciaefeticay); 
//printf("%.2f>%.2f\n",inerciaX,inerciaefeticay); 
if(inerciaX>inerciaefeticay){ 
areatotal=2*area; 
esbeltezefetiva=sqrt(areatotal/inerciaefeticay)*L; 
if(esbeltezefetiva<140){ 
//printf("\nL=%.f  - ECOD1=%.f-  Forca=%.f N  - InerciaY=%.2f  -  Inercia2=%.3f  -  Base=%.f mm  -  altura=%.f\n",L,ECOD1,esfobarra1,inerciaefeticay,inercia2,base,altura,a1); 
CSgo=compressaodebarracomposta(L,ECOD1,esfobarra1,inerciaefeticay,inercia2,base,altura,a1); 
if(CSgo<FCOD1){ 
m=0; 
//printf("Perfeito %.2f<=%.2f\n",CSgo,FCOD1); 
dw++; 
} 
else{ 
mudancadem++; 
//printf("CSGO muito alto%.2f\n",CSgo); 
} 
} 
else{ 
mudancadem++; 
//printf("%.2f\n",esbeltezefetiva); 
} 
} 
else{ 
//printf("Maatual -%.2f\n",m1[mudancadem]); 
mudancadem++; 
//printf("Mnovo -%.2f\n",m1[mudancadem]); 
} 
} 
}while(m!=0); 
} 
} 
if(i<=2*rep){ 
alturabi=altura; 
basebi=base; 
} 
else{ 
alturadi=altura; 
basedi=base; 
} 
}while(dw==0); 
//printf("\n\n\n\n\t%f,%f,%f,%f\n\n%f,%f\n\n\n",alturabi,basebi,alturadi,basedi,altura,base); 
if(i<=2*rep){ 
alturabi=altura; 
basebi=base; 
} 
else{ 
alturadi=altura; 
basedi=base; 
} 
} 
} 
t=VY[2]/mpm; 
teta=atan(t); 
teta1=(PI/2)-teta; 
for(i=1;i<=4*rep-3;i++){ 
esfoliga1[i]=fabs(esfoliga[i]*1000); 
//printf("%d - %6.6f - %6.6f\n",i,esfoliga1[i],esfoliga[i]); 
} 
base2=basemo;//mon 
base3=basedi;//diago 
base=basebi;//ban 
j=1; 
Fe0=FCOD/pow(10,6); 
Fe90=embut90(Fe0,j); 
dpino=0; 
i=1; 
switch(estilotrelica){ 
case 1: 
do{ 
for(i=1;i<=rep/2+1;i++){ 
n=0; 
if(i==1){//banzo superior e inferior 
d2=dpino; 
n=4; 
t=menor(base/2,base2/2,base3); 
Fteta=embutimento(Fe0,Fe90,teta); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*(pow(t,2)/beta)*Fteta; 
u1=rep+1; 
if(fabs(esfoliga1[1])>=fabs(esfoliga1[u1])){ 
ND=esfoliga1[1]; 
} 
else{ 
Xind=rep+1; 
ND=esfoliga1[Xind]; 
} 
n1=ND/(n*rvd1); 
Npino[i]=pinon(n1); 
} 
else if(i==rep/2+1){//montante central n� superior 
u1=rep/2; 
u2=5*rep/2; 
if(esfoliga1[u1]>=esfoliga1[u2]){//pois refer�ncia � o montante 
Xind=rep/2; 
ND=esfoliga1[Xind]; 
n=4; 
t=menor(base/2,base2/2,base3); 
} 
else{//pois o banzo � a referencia 
Xind=5*rep/2; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor2(base,base2/2); 
} 
Fteta=embutimento(Fe0,Fe90,teta1); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n1=ND/(n*rvd1); 
Npino[i]=pinon(n1); 
} 
else if(i>1 && i<rep/2+1){//banzo superior tirando o 1 e rep+1 e central 
//1 
Xind=2*rep-1+i; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor(base/2,base2/2,base3); 
Fteta=embutimento(Fe0,Fe90,teta1); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n1=ND/(n*rvd1); 
//2 
Xind=3*rep-2+i; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor2(base,base2/2); 
teta2=atan(VY[i]/mpm)+teta; 
Fteta=embutimento(Fe0,Fe90,teta2); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n2=ND/(n*rvd1); 
if(n1>=n2){ 
Npino[i]=pinon(n1); 
} 
else{ 
Npino[i]=pinon(n2); 
} 
} 
} 
teta1=PI/2; 
for(i=rep+2;i<=3*rep/2+1;i++){ 
if(i==rep+2){//s� montante em rela��o ao banzo 
Npino[i]=2; 
} 
else if(i>rep+2 && i<=3*rep/2+1){//s� montante em rela��o ao banzo 
//1 
Xind=rep+i-1; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor(base/2,base2/2,base3); 
Fteta=Fe90; 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n1=ND/(n*rvd1); 
//2 
Xind=i-(rep+1); 
teta2=atan(VY[Xind]/mpm); 
Xind=2*rep-3+i; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor2(base,base2/2); 
Fteta=embutimento(Fe0,Fe90,teta2); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n2=ND/(n*rvd1); 
if(n1>=n2){ 
Npino[i]=pinon(n1); 
} 
else{ 
Npino[i]=pinon(n2); 
} 
} 
} 
}while(d2!=dpino); 
break; 
case 2: 
do{ 
for(i=1;i<=rep/2+1;i++){ 
u=2*rep-(2*rep-2); 
if(i==1){//banzo superior e inferior 
d2=dpino; 
//printf("%d\n",i); 
n=4; 
t=menor(base/2,base2/2,base3); 
Fteta=embutimento(Fe0,Fe90,teta); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
u1=rep+1; 
if(fabs(esfoliga1[1])>=fabs(esfoliga1[u1])){ 
ND=esfoliga1[1]; 
} 
else{ 
Xind=rep+1; 
ND=esfoliga1[Xind]; 
} 
n1=ND/(n*rvd1); 
Npino[i]=pinon(n1); 
} 
else if(i==rep/2+1){//montante central n� superior 
u1=rep/2; 
u2=rep*3-2+facy; 
if(fabs(esfoliga1[u1])>=fabs(esfoliga1[u2])){//pois refer�ncia � o montante 
Xind=rep/2; 
ND=esfoliga1[Xind]; 
n=4; 
t=menor(base/2,base2/2,base3); 
} 
else{//pois o banzo � a refer�ncia 
Xind=rep*3-2+facy; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor2(base,base2/2); 
} 
teta2=atan(VY[i]/mpm)-teta; 
Fteta=embutimento(Fe0,Fe90,teta2); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n1=ND/(n*rvd1); 
Npino[i]=pinon(n1); 
} 
else if(i==u){//s� montante em rela��o ao banzo 
Xind=2*rep+1; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor2(base,base2/2); 
Fteta=embutimento(Fe0,Fe90,teta1); 
//printf("%f-t||Fteta-%f\n%f-F0||F90-%f\n",t,Fteta,Fe0,Fe90); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n1=ND/(n*rvd1); 
Npino[i]=pinon(n1); 
} 
else{//resto, banzo 
//1 
Xind=2*rep-1+i; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor(base/2,base2/2,base3); 
Fteta=embutimento(Fe0,Fe90,teta1); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n1=ND/(n*rvd1); 
//2 
Xind=3*rep-3+i; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor2(base,base2/2); 
teta2=atan(VY[i]/mpm); 
Fteta=embutimento(Fe0,Fe90,teta2); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n2=ND/(n*rvd1); 
if(n1>=n2){ 
Npino[i]=pinon(n1); 
} 
else{ 
Npino[i]=pinon(n2); 
} 
} 
} 
for(i=rep+2;i<=3*rep/2+1;i++){ 
if(i==3*rep/2+1){//montante central n� inferior 
Npino[i]=2; 
} 
else if(i>=rep+2 && i<3*rep/2+1){//banzo inferior do rep+2 a central 
//1 
Xind=rep-1+i; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor(base/2,base2/2,base3); 
Fteta=Fe90; 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n1=ND/(n*rvd1); 
//2 
Xind=i-(rep-1); 
teta2=atan(VY[Xind]/mpm); 
Xind=2*rep-2+i; 
ND=esfoliga1[Xind]; 
n=2; 
t=menor2(base,base2/2); 
Fteta=embutimento(Fe0,Fe90,teta2); 
emb=1; 
do{ 
emb=betas(t,dpino,Fteta); 
if(emb==1){ 
dpino++; 
} 
}while(emb==1); 
beta=t/pino(0,dpino); 
rvd1=0.4*pow(t,2)/beta*Fteta; 
n2=ND/(n*rvd1); 
if(n1>=n2){ 
Npino[i]=pinon(n1); 
} 
else{ 
Npino[i]=pinon(n2); 
} 
} 
} 
}while(d2!=dpino); 
break; 
} 
for(i=1;i<=rep/2;i++){ 
u=-i+rep+2; 
Npino[u]=Npino[i]; 
} 
u=2*rep; 
for(i=rep+2;i<=3*rep/2+1;i++){ 
Npino[u]=Npino[i]; 
u--; 
} 
Maxpino=0; 
fprintf(arq,"\n"); 
fprintf(arq,"n�    - Pinos\n"); 
for(i=1;i<=2*rep;i++){ 
Maxpino=Maxpino+Npino[i]; 
fprintf(arq,"n� %d - %.0f\n",i,Npino[i]); 
} 
//----------------------------------------------------------------------------------------------------------     
basebi=basebi/1000.0; 
basebs=basebi; 
basemo=basemo/1000.0; 
basedi=basedi/1000.0; 
alturabi=alturabi/1000.0; 
alturabs=alturabi; 
alturamo=alturamo/1000.0; 
alturadi=alturadi/1000.0; 
  
//area1 = rep+1 
//volume 
//duplo banzos 
volbi=mpm/100*basebi*alturabi; 
volbs=barras[1]/100*basebs*alturabs; 
volterca=lterca*baseterca*alturaterca; 
//peso 
pesomad=(volbi+volbs+volterca)*densidade; 
pesotelha1=pesotelha*((barras[1]/2)+BMA)*lterca; 
pesototal[1]=(pesomad+pesotelha1)*1.03; 
u=rep+1; 
pesototal[u]=pesototal[1]; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
  
//area 2 = n� = rep 
//volume 
if(rep>2) 
{ 
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
vold0=barras[rep*3]/100*basedi*alturadi;//base 6*12 
volmo=barras[rep*2+1]/100*basemo*alturamo; 
volterca=lterca*baseterca*alturaterca; 
  
pesomad=(volbi+volbs+volterca+volmo+vold0)*densidade; 
pesotelha1=pesotelha*barras[1]*lterca; 
pesototal[2]=(pesomad+pesotelha1)*1.03; 
pesototal[rep]=pesototal[2]; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
} 
//area 3 at� area (rep/2) = rep-1 a rep/2+2 
if(rep>4) 
{ 
u=rep-1; 
x=rep*3; 
for(i=3;i<=rep/2;i++) 
{ 
  
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
vold1=barras[x]/100*basedi*alturadi;//base 6*12 
vold2=barras[x+1]/100*basedi*alturadi; 
volmo=barras[u]/100*basemo*alturamo; 
volterca=lterca*baseterca*alturaterca; 
  
pesomad=(volbi+volbs+volterca+volmo+vold1+vold2)*densidade; 
pesotelha1=pesotelha*barras[1]*lterca; 
pesototal[i]=(pesomad+pesotelha1)*1.03; 
pesototal[u]=pesototal[i]; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
x++; 
u--; 
} 
} 
//area rep/2+1 
  
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
u=rep*3-2+facy; 
vold0=2*barras[u]/100*basedi*alturadi;//base 6*12 
volmo=barras[rep*3-1]/100*basemo*alturamo; 
volterca=2*lterca*baseterca*alturaterca; 
  
pesomad=(volbi+volbs+volterca+volmo+vold1+vold2)*densidade; 
pesotelha1=pesotelha*barras[1]*lterca; 
i=rep/2+1; 
pesototal[i]=(pesomad+pesotelha1)*1.03; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
pesofinal=0; 
for(i=1;i<=rep+1;i++) 
{ 
pesototal[i]=pesototal[i]/100; 
//printf("peso %d - %f kn\n",i,pesototal[i]); 
pesofinal=pesofinal+pesototal[i]; 
} 
pesoinicial=pesoinicial*1.1; 
system("pause"); 
system("cls"); 
}while(pesoinicial<=pesofinal); 
  
/*Cria��o de um arquivo de dados*/ 
  
fprintf(arq,"\nTer�a\nBase-%f\nAltura-%f\n\nBanzo Inferior\nBase-%f\nAltura-%f\n\nBanzo Superior\nBase-%f\nAltura-%f\n\nMontante\nBase-%f\nAltura-%f\n\nDiagonal\nBase-%f\nAltura-%f\nPeso\nInicial * 1.1\t|\tFinal\n%f\t>=\t%f",baseterca,alturaterca,basebi,alturabi,basebs,alturabs,basemo,alturamo,basedi,alturadi,pesoinicial,pesofinal); 
//area1 = rep+1 
//volume 
//duplo banzos 
volbi=mpm/100*basebi*alturabi; 
volbs=barras[1]/100*basebs*alturabs; 
//peso 
volumetotal[1]=(volbi+volbs)*densidade; 
u=rep+1; 
volumetotal[u]=volumetotal[1]; 
//area 2 = n� = rep 
//volume 
if(rep>2) 
{ 
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
vold0=barras[rep*3]/100*basedi*alturadi;//base 6*12 
volmo=barras[rep*2+1]/100*basemo*alturamo; 
volumetotal[2]=(volbi+volbs+volterca+volmo+vold0)*densidade; 
volumetotal[rep]=volumetotal[2]; 
} 
//area 3 at� area (rep/2) = rep-1 a rep/2+2 
if(rep>4) 
{ 
u=rep-1; 
x=rep*3; 
for(i=3;i<=rep/2;i++) 
{ 
  
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
vold1=barras[x]/100*basedi*alturadi;//base 6*12 
vold2=barras[x+1]/100*basedi*alturadi; 
volmo=barras[u]/100*basemo*alturamo; 
volumetotal[i]=(volbi+volbs+volmo+vold1+vold2)*densidade; 
volumetotal[u]=volumetotal[i]; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
x++; 
u--; 
} 
} 
//area rep/2+1 
  
volbi=2*mpm/100*basebi*alturabi; 
volbs=2*barras[1]/100*basebs*alturabs;//base 3*12 
u=rep*3-2+facy; 
vold0=2*barras[u]/100*basedi*alturadi;//base 6*12 
volmo=barras[rep*3-1]/100*basemo*alturamo; 
volumetotal[i]=(volbi+volbs+volmo+vold1+vold2); 
i=rep/2+1; 
//printf("\nvolbi-%f\nvolbs-%f\nvolterca-%f\nvold0-%f\nvolmo-%f\npesomad-%f\npesotelha1-%f\n\npesototal-%f\n",volbi,volbs,volterca,vold0,volmo,pesomad,pesotelha1,pesototal[i]); 
volumefinal=0; 
for(i=1;i<=rep+1;i++) 
{ 
volumetotal[i]=volumetotal[i]; 
volumefinal=volumefinal+volumetotal[i]; 
} 
volterca=lterca*baseterca*alturaterca; 
volumefinal=volumefinal/1000; 
printf("Volume de uma Treli�a - %f - %f\n",volumefinal); 
printf("Volume de um conjunto de ter�a - %f",volterca*rep); 
//----------------------------------------------------------------------------------------------------------- 
printf("\nQual o tamanho da base do contraventamento(cm)*Recomend�vel 6 cm*:"); 
scanf("%f",&basecontra); 
printf("Qual o tamanho da altura do contraventamento(cm)*Recomend�vel 12 cm*:"); 
scanf("%f",&alturacontra); 
basecontra=basecontra*10; 
alturacontra=alturacontra*10; 
f1=rep/2; 
F1=esfoliga[f1]; 
f2=3*rep/2; 
F2=esfoliga[f2]; 
f3=5*rep/2; 
F3=esfoliga[f3]; 
f4=7*rep/2-2; 
F4=esfoliga[f4]; 
forca1=maior(F1,F2,F3,F4); 
forca2=menor3(F1,F2,F3,F4); 
teta=Lterca[contadorterca]/alturatrelica; 
teta=atan(teta); 
u=Lterca[contadorterca]; 
//printf("\n\n\n\n%d\n\n\n\n",u); 
alturatrelica=alturatrelica*100; 
L=pow(u,2)+pow(alturatrelica,2); 
//printf("\n\n\n\n%f\n\n\n\n",L); 
L=sqrt(L); 
Lcontra=L; 
//printf("\n\n\n\n%f\n\n\n\n",L); 
L=L*10; 
inerciaX=basecontra*pow(alturacontra,3)/12; 
inerciaY=alturacontra*pow(basecontra,3)/12; 
if(inerciaX<inerciaY){ 
inercia=inerciaX; 
} 
else{ 
inercia=inerciaY; 
} 
inerciamin=sqrt(inercia/(basecontra*alturacontra)); 
esbeltez=L/inerciamin; 
//printf("\n\n%f  - Esbeltez %f  - inerciamin %f\n\n",L,esbeltez,inerciamin); 
if(esbeltez>140){ 
L=L/2; 
} 
//printf("\n\n%f  -  %f\n\n",L,esbeltez); 
if(fabs(forca1)>=fabs(forca2)){ 
co=0; 
do{ 
if(forca1>=0){ 
forca1=forca1*1000*cos(teta)/150; 
tensao=forca1/(basecontra*alturacontra); 
if(tensao<=FCOD1){ 
co++; 
//printf("Tens�o- %f - %f\n",tensao,FCOD1); 
} 
else if(basecontra>(alturacontra/4-10)){ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f\n",alturacontra,basecontra); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f\n",basecontra,alturacontra); 
} 
} 
else{ 
forca1=-forca1*1000*cos(teta)/150; 
inerciaX=basecontra*pow(alturacontra,3)/12; 
inerciaY=alturacontra*pow(basecontra,3)/12; 
if(inerciaX<inerciaY){ 
inercia=inerciaX; 
} 
else{ 
inercia=inerciaY; 
} 
inerciamin=sqrt(inercia/(basecontra*alturacontra)); 
esbeltez=L/inerciamin; 
//printf("Inercia min - %f=%f|%f\tEsbeltez - %f\n",inerciamin,L,(basecontra*alturacontra),esbeltez); 
if(esbeltez<40){ 
tensao=forca1/(basecontra*alturacontra); 
if(tensao<=FCOD1){ 
co++; 
//printf("Tens�o- %f - %f\n",tensao,FCOD1); 
} 
else if(basecontra>(alturacontra/4-10)){ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f\n",alturacontra, basecontra); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f\n",basecontra,alturacontra); 
} 
} 
else if(40<=esbeltez && 80>esbeltez){ 
CSgo=comont(forca1,ECOD1,FCOD1,inercia,L,basecontra,alturacontra); 
if(CSgo<=1){ 
co++; 
printf("\n"); 
} 
else if(basecontra>(alturacontra/4-10)){ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f  CSgo=%5.5f\n",alturacontra, basecontra,CSgo); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f  CSgo=%5.5f\n",basecontra,alturacontra,CSgo); 
} 
} 
else if(80<=esbeltez && 140>esbeltez){ 
CSgo=comont(forca1,ECOD1,FCOD1,inercia,L,basecontra,alturacontra); 
//printf("CSgo=%5.5f\nND=%5.5f\nECOD=%5.5f\nFCOD1%5.5f\nINERCIA=%5.5f\nL=%5.5f\nBASE=%5.5f\nAltura=%5.5f\n",CSgo,forca1,ECOD1,FCOD1,inerciamin,L,basecontra,alturacontra); 
if(CSgo<=1){ 
//printf("\n\n\n"); 
co++; 
} 
else if(basecontra>(alturacontra/4-10)){ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f  CSgo=%5.5f\n",alturacontra, basecontra,CSgo); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f  CSgo=%5.5f\n",basecontra,alturacontra,CSgo); 
} 
} 
else{ 
if(basecontra>(alturacontra/4-10)) 
{ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f Esbeltez\n",alturacontra, basecontra); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f Esbeltez\n",basecontra,alturacontra); 
} 
} 
} 
system("CLS"); 
}while(co==0); 
} 
else{//somente � em compress�o 
do{ 
forca2=-forca2*1000; 
inerciaX=basecontra*pow(alturacontra,3)/12; 
inerciaY=alturacontra*pow(basecontra,3)/12; 
if(inerciaX<inerciaY){ 
inercia=inerciaX; 
} 
else{ 
inercia=inerciaY; 
} 
inerciamin=sqrt(inercia/(basecontra*alturacontra)); 
esbeltez=L/inerciamin; 
//printf("Inercia min - %f=%f/%f\tEsbeltez - %f\n",inerciamin,inercia,(basecontra*alturacontra),esbeltez); 
if(esbeltez<40){ 
tensao=forca2/(basecontra*alturacontra); 
if(tensao<=FCOD1){ 
co++; 
//printf("Tens�o- %f - %f\n",tensao,FCOD1); 
} 
else if(basecontra>(alturacontra/4-10)){ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f\n",alturacontra, basecontra); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f\n",basecontra,alturacontra); 
} 
} 
else if(40<=esbeltez && 80>esbeltez){ 
CSgo=comont(forca2,ECOD1,FCOD1,inercia,L,basecontra,alturacontra); 
if(CSgo<=1){ 
co++; 
printf("\n"); 
} 
else if(basecontra>(alturacontra/4-10)){ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f  CSgo=%5.5f\n",alturacontra, basecontra,CSgo); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f  CSgo=%5.5f\n",basecontra,alturacontra,CSgo); 
} 
} 
else if(80<=esbeltez && 140>esbeltez){ 
CSgo=comont(forca2,ECOD1,FCOD1,inercia,L,basecontra,alturacontra); 
//printf("CSgo=%5.5f\nND=%5.5f\nECOD=%5.5f\nFCOD1%5.5f\nINERCIA=%5.5f\nL=%5.5f\nBASE=%5.5f\nAltura=%5.5f\n",CSgo,forca2,ECOD1,FCOD1,inerciamin,L,basecontra,alturacontra); 
if(CSgo<=1){ 
//printf("\n\n\n"); 
co++; 
} 
else if(basecontra>(alturacontra/4-10)){ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f  CSgo=%5.5f\n",alturacontra, basecontra,CSgo); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f  CSgo=%5.5f\n",basecontra,alturacontra,CSgo); 
} 
} 
else{ 
if(basecontra>(alturacontra/4-10)){ 
alturacontra=alturacontra+10; 
//printf("New alturacontra %f - %f Esbeltez\n",alturacontra, basecontra); 
} 
else{ 
basecontra=basecontra+10; 
//printf("New Base %f - %f Esbeltez\n",basecontra,altura); 
} 
} 
system("CLS"); 
}while(co==0); 
} 
/*Cria��o de um arquivos de dados*/ 
fprintf(arq,"\nVolume de uma Treli�a - %.2f\n",volumefinal); 
fprintf(arq,"Volume de um conjunto de ter�a - %.2f\n",volterca*rep); 
volumecontra=alturacontra*basecontra*Lcontra*2/100; 
printf("Pre�o do m� da madeira(R$):"); 
scanf("%f",&goldmad); 
volumefinal=volumefinal+volterca*rep; 
fprintf(arq,"O valor de gasto com madeira com valor de m� de %.2f ser� %.2f reais.\n",goldmad,goldmad*volumefinal*((comprimentotrelica1/u)+1)); 
printf("Pre�o do m� do tratamento da madeira(R$):"); 
scanf("%f",&goldtrat); 
fprintf(arq,"O valor de gasto com o tratamento da madeira com valor de m� de %.2f ser� %.2f reais.\n",goldtrat,goldtrat*volumefinal*((comprimentotrelica1/u)+1)); 
system("PAUSE"); 
return 0; 
}
