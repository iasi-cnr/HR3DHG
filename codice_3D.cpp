
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>
#include <iostream>        
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <complex>


#define Dxx 3600.0 // m^2/h
#define Dyy 3600.0 // m^2/h
#define Dzz 3.6 // m^2/h
#define vz0 0.0 // m/h
#define kDSPM0 pow(10.0,5.025) // l/Kg
#define kD0 pow(10.0,5.025) //210000 // l/Kg
#define	kDIIsed pow(10.0,5.0) //l/Kg
#define	kDMMsed pow(10.0,2.5) //l/Kg
#define VFCII 27500 // l/Kg
#define VFCMM 800000 // l/Kg
#define kPhde 0.00216 // 1/h
#define kmeth 0.000126  //0.00138 // 1/h
#define k1phox 0.0000066 // m^2/W*s
#define k2phre 0.0000016 // m^2/W*s
#define k3bio 140.0 // m^3/mol
#define k4bio 86.0 // m^3/mol
#define det 24.0 // h
#define H1 0.479 // dimensionless
#define uwind 3.83 // m/s 
#define PMCO2 44.01 // g/mol
#define PMHg0 200.59 // g/mol
#define PMH2O 18.02 // g/mol
#define PMHgII 200.59 // g/mol
#define PMMMHg 215.63 // g/mol
#define Qs 0.0 // m^3/h
#define As 1.0 // m^2
#define SLII 0.0 // ng/(l * h)
#define lambda1 0.52 //0.99 // dimensionless
#define chlas 0.205 // mg/m^3  
#define Dwin 0.000002534 // m^2/h
#define Dwor 0.000002534 // m^2/h
#define delsed 0.00009 // m
#define delsedMM 0.00030 // m
#define delw 0.0001 // m
#define Kdeme 0.007177 // 1/h
#define Kme 0.000503 // 1/h
#define kMM 0.004 // dimensionless 
#define alfa  0.0000001    // 1/h
#define DHgextb27 0.26 // ng/l
#define DHgextb26 0.26 // ng/l
#define DHgextm27 0.26 // ng/l
#define DHgextm26 0.26 // ng/l
#define DHgexts27 0.26 // ng/l
#define DHgexts26 0.26 // ng/l
#define THgextb27 0.31 // ng/l
#define THgextb26 0.31 // ng/l
#define THgextm27 0.31 // ng/l
#define THgextm26 0.31 // ng/l
#define THgexts27 0.31 // ng/l
#define THgexts26 0.31 // ng/l
#define SPMextb27 0.00001870 // Kg/l
#define SPMextb26 0.00001865 // Kg/l
#define SPMextm27 0.00001870 // Kg/l
#define SPMextm26 0.00001865 // Kg/l
#define SPMexts27 0.00001830 // Kg/l
#define SPMexts26 0.00001865 // Kg/l
#define Lsci 300.0 // m
#define Llev 400.0 // m
#define SLMM 0.0 // ng/(l * h)
#define MMHgatm 0.0 // ng/m^3
#define Drydep 0.0 // mg/(m^-2 * h)  
#define ws 0.174  // m/h
#define Td 1814400.0 // Kg/(m*h^2)
#define Tr 4147200.0 // Kg/(m*h^2)
#define emax 111.25 // g/(m^2*h)
#define lambdac 0.000208 // 1/h
#define delhu 0.02 // m 
#define phiSPMatm 0.001256 // g/(m^2*h)
#define g 9.80665 // m/sec^2
#define ks 36.0 // m^(1/3)/s
#define romw 1025.0 // Kg/m^3
#define Vpce1 4188.787 // microm^3/cell
#define Wp1 0.004188787 // microg
#define ag 0.22 // dimensionless
#define bg 0.15 // dimensionless
#define kp 0.25 // dimensionless
#define pcap 0.29 // dimensionless
#define rolip 32.0 // ? d
#define rowat 0.0068 // ? d
#define rowatfood 0.0002 // ? d
#define logKow 2.54 // dimensionless
#define logBCFMM 4.4 // l/Kg
#define hlmet  250.0 //?  d
#define Twat  20.0 // °C
#define Wzoo 0.027 // g
#define kzgr 0.016 // 1/d
#define kzurII 1.14 // l/g*d
#define kzurMM 1.59 // l/g*d
#define kzexrII 0.005 // 1/d
#define kzexrMM 0.00003 // 1/d
#define kzegII 0.089 // 1/d
#define kzegMM 0.052 // 1/d
#define plipPhy 0.02 // ? dimensionless
#define plipZoo 0.04 // ? dimensionless
#define plipFish 0.09 //  dimensionless
#define gamfood 0.041 //  1/d
#define logKoc 5.00 //  dimensionless
#define blip 0.41 // dimensionless
#define logkdII 5.4 // dimensionless
#define logkdMM 5.0 // dimensionless
#define Lfish  11.56  // cm
#define aWf 0.0085     // dimensionless
#define bWf 3.11     //  dimensionless
#define aBCF 2.03    // ? dimensionless
#define bBCF -0.57    // ? dimensionless
#define kal 0.28    //  dimensionless
#define tfish  730.0 // d
#define kzinII 0.104 // g/g*d
#define kzinMM 0.151 // g/g*d
#define AssFoodzooII 0.060 //  dimensionless
#define AssFoodzooMM 0.800 //  dimensionless
#define AssFoodII 0.030 // ? dimensionless
#define AssFoodMM 0.999 //  dimensionless
#define PrefPhy  0.60    // dimensionless
#define PrefZoo  0.75    // dimensionless
#define Prefsed  0.25    // dimensionless
#define epsilon1 0.52 // dimensionless
#define r1 0.096 // 1/h
#define m1 0.010  // 1/h
#define Y1 500000000000 // cell/mmol phosphorus
#define abg 0.060 // 1/m
#define a1 0.012 // m^2/mg chl-a
#define a2 0.020 // m^2/mg chl-a
#define KR1 0.200 // mmol phosphorus/m^3
#define KI1 67.50 // micromol photons/(m^2 * s)
#define v1 0.000098 // m/h
#define Rin 0.010000 // mmol phosphorus/m^3
#define Rbot 0.100000 // mmol phosphorus/m^3
#define chla2 0.041  // mg/m^3
#define tempo 8760 // h
#define M 105120 // 1/12 h
#define N 25 // years (modificato Ale)
#define I 10  // nodes along x axis
#define J 18  // nodes along y axis
#define K 6   // vertical layers number in seawater
#define RL 10   // vertical layers number in sediments
#define T 4  // Mullus Barbatus lifetime
#define T1 8
#define SUR 128 // pixel number within the basin
#define klev 5  // inlet 1 (Levante) depth
#define ksci 2  // inlet 2 (Scirocco) depth
#define L 12 // y-position of inlet 1
#define C 7  // x-position of inlet 2
#define H 9  // position external area 3 
#define iext1 9  // x-position of external area 1
#define iext2 9  // x-position of external area 2
#define iext3 9  // x-position of external area 3
#define jext1 8  // y-position of external area 1
#define jext2 16 // y-position of external area 2
#define jext3 17 // y-position of external area 3
#define P 528700 //
#define Q 365 // d
#define S 2
#define	dx 454.6 // m
#define	dy 454.6 // m
#define	dz 5.0 // m
#define	dz1 0.1 // m
#define	dz2 0.2 // m
#define B1 600000000.0 // cell/m^3
#define B1ext 600000000.0 // cell/m^3
#define dlHg  1.9 // ng/l  (detection limit for DHg and THg)
#define NPP 0.020417 // g C/m^2 * h



int main(int argc, char *argv[])
{

    FILE *fb1, *fct, *fR, *fI, *fHg0, *fHgII, *fMMHg, *fDHg, *fTHg, *fSPM, *fHgIIpw, *fMMHgpw; 
    FILE *fHgIIfluxsed, *fMMHgfluxsed;
    FILE *fHg0fluxatm, *fHg0fluxdep, *fHgIIfluxdep, *fMMHgfluxdep, *fP, *fZ, *fFi, *fZtmean, *fFitmean, *fFisptmean, *fu, *fRelease, *fOutflow, *fEvasion, *fRecycled;
    FILE *fv5, *fv10, *fv20, *fv30, *fero, *fero2;
    FILE *fIin, *fPrec, *fTatm, *fHggas, *fHgIIatm, *fRin1,  *fRin2,  *fRin3,  *fRin4, *fRin5, *fRin6, *fRin7;
    FILE *fSPMin1, *fSPMin2, *fSPMin3, *fSPMin4, *fSPMin5, *fSPMin6, *fSPMin7, *fSPOMin1, *fSPOMin2, *fSPOMin3, *fSPOMin4, *fSPOMin5, *fSPOMin6, *fSPOMin7;
    FILE *fTHgsedin,  *fTHgsedin2, *fTHgsedin3, *fTHgsedin4,  *fTHgsedin5, *fTHgsedin6, *fTHgsedin7,  *fTHgsedin8, *fTHgsedin9, *fTHgsedin10;
    FILE *fTHgsed, *ftotdep;
    FILE *fSWsed;
    FILE *fporsed;
    FILE *fporsed2, *fporsed3, *fporsed4, *fporsed5, *fporsed6, *fporsed7, *fporsed8, *fporsed9, *fporsed10;
    FILE  *fTOCsed;
    
    int i, j, k, m, n, p, q, r, idt, idtb;
    double Hg0[I+2][J+2][K+2], HgII[I+2][J+2][K+2], MMHg[I+2][J+2][K+2], DHg[I+2][J+2][K+2], THg[I+2][J+2][K+2], SPIM[I+2][J+2][K+2], SPOM[I+2][J+2][K+2], SPM[I+2][J+2][K+2], forg[I+2][J+2][K+2];
    double k1[I+2][J+2][K+2], k2[I+2][J+2][K+2];
    double Rin1[I+2][J+2], Rin2[I+2][J+2], Rin3[I+2][J+2], Rin4[I+2][J+2], Rin5[I+2][J+2], Rin6[I+2][J+2];
    double SPMin1[I+2][J+2], SPMin2[I+2][J+2], SPMin3[I+2][J+2], SPMin4[I+2][J+2], SPMin5[I+2][J+2], SPMin6[I+2][J+2], SPOMin1[I+2][J+2], SPOMin2[I+2][J+2], SPOMin3[I+2][J+2], SPOMin4[I+2][J+2], SPOMin5[I+2][J+2], SPOMin6[I+2][J+2];
    double THgsedin[I+2][J+2], SWsedin[I+2][J+2], TOCsedin[I+2][J+2], porsedin[I+2][J+2], Iinin[Q+1][S+1], Tatmin[Q+1][S+1], Prin[Q+1][S+1], HgIIatmin[Q+1][S+1], Hggasin[Q+1][S+1];  
    double porsedin2[I+2][J+2], porsedin3[I+2][J+2], THgsedin2[I+2][J+2],  THgsedin3[I+2][J+2];
    double porsedin4[I+2][J+2], porsedin5[I+2][J+2], porsedin6[I+2][J+2], porsedin7[I+2][J+2], porsedin8[I+2][J+2], porsedin9[I+2][J+2], porsedin10[I+2][J+2];
    double THgsedin4[I+2][J+2], THgsedin5[I+2][J+2], THgsedin6[I+2][J+2], THgsedin7[I+2][J+2], THgsedin8[I+2][J+2], THgsedin9[I+2][J+2], THgsedin10[I+2][J+2]; 
    double PHgII[I+2][J+2][K+2], PMMHg[I+2][J+2][K+2], PHg[I+2][J+2][K+2], PHgIItmean[I+2][J+2][K+2], PMMHgtmean[I+2][J+2][K+2], PHgIItmean2[I+2][J+2][K+2], PMMHgtmean2[I+2][J+2][K+2];
    double Wfish, kfgr, kfin, kfegr, logBCFII[I+2][J+2], kfurII[I+2][J+2], kfurMM, kfexrII[I+2][J+2], kfexrMM, lambmet;
    double plipfood, kfinMM, kfegrMM, pcarsed[I+2][J+2], kfinMMsed[I+2][J+2], kfegrMMsed[I+2][J+2], DietHgII[I+2][J+2], DietMMHg[I+2][J+2];
    double FiHgIIre[I+2][J+2], FiHgIIGIT[I+2][J+2], FiHgIIGITdet[I+2][J+2], FiMMHgre[I+2][J+2], FiMMHgGIT[I+2][J+2], FiMMHgGITdet[I+2][J+2], FiHgII[I+2][J+2], FiMMHg[I+2][J+2], FiHgIItmean[I+2][J+2], FiMMHgtmean[I+2][J+2], FiHgIItmean2[I+2][J+2], FiMMHgtmean2[I+2][J+2];
    double DietzooHgII[I+2][J+2], DietzooMMHg[I+2][J+2], ZHgIIre[I+2][J+2], ZHgIIGIT[I+2][J+2], ZMMHgre[I+2][J+2], ZMMHgGIT[I+2][J+2], ZHgII[I+2][J+2], ZMMHg[I+2][J+2], ZHgIItmean[I+2][J+2], ZMMHgtmean[I+2][J+2], ZHgIItmean2[I+2][J+2], ZMMHgtmean2[I+2][J+2];
    double PHgIIsptmean, PMMHgsptmean, ZHgIIsptmean, ZMMHgsptmean, FiHgIIsptmean, FiMMHgsptmean;
    double PHgIIsptmean2, PMMHgsptmean2, ZHgIIsptmean2, ZMMHgsptmean2, FiHgIIsptmean2, FiMMHgsptmean2;
    double MTCwaw[I+2][J+2], MTCwag[I+2][J+2], MTCwa[I+2][J+2]; 
    double SIIDOM[I+2][J+2][K+2], SIISPM[I+2][J+2][K+2], MTCIIsw[I+2][J+2], Dinsed[I+2][J+2][RL+2];
    double HgIIpw[I+2][J+2][RL+2];
    double SMMDOM[I+2][J+2][K+2], SMMSPM[I+2][J+2][K+2], MTCMMsw[I+2][J+2], Dorsed[I+2][J+2][RL+2];
    double MMHgpw[I+2][J+2][RL+2];
    double fluxHgIIsed[I+2][J+2], fluxMMHgsed[I+2][J+2];
    double fluxHg0atm[I+2][J+2], fluxHg0dep[I+2][J+2], fluxHgIIdep[I+2][J+2], fluxMMHgdep[I+2][J+2];
    double SLSPM[I+2][J+2][K+2];
    double b1[I+2][J+2][K+2], chla1[I+2][J+2][K+2], chlatot[I+2][J+2][K+2];
    double R[I+2][J+2][K+2], Rini[I+2][J+2][K+2], Iin, Tatm, Pr, HgIIatm, It[I+2][J+2][K+2], THgsed[I+2][J+2][RL+2], SWsed[I+2][J+2], TOCsed[I+2][J+2], porsed[I+2][J+2][RL+2];
    double THgsedold[I+2][J+2][RL+2];
    double G1[I+2][J+2][K+2], sommab1[I+2][J+2], sommab2[I+2][J+2];
    double F1R[I+2][J+2][K+2], F1I[I+2][J+2][K+2];
    double sumfluHg0x[I+2][J+2], sumfluHgIIx[I+2][J+2], sumfluMMHgx[I+2][J+2], sumfluTHgx[I+2][J+2], sumfluvx[I+2][J+2];
    double sumfluHg0xs[I+2][J+2], sumfluHgIIxs[I+2][J+2], sumfluMMHgxs[I+2][J+2], sumfluTHgxs[I+2][J+2], sumfluvxs[I+2][J+2];
    double sumfluHg0y[I+2][J+2], sumfluHgIIy[I+2][J+2], sumfluMMHgy[I+2][J+2], sumfluTHgy[I+2][J+2], sumfluvy[I+2][J+2];
    double **value1, **value2, **value3, **value5, **ero, **ero2;
    double vxc[I+2][J+2][K+2], vyc[I+2][J+2][K+2], vx[I+2][J+2][K+2], vy[I+2][J+2][K+2], vxold[I+2][J+2][K+2], vyold[I+2][J+2][K+2], vz[I+2][J+2][K+2], dep[I+2][J+2], depold[I+2][J+2], Totdep[I+2][J+2], Totdepold[I+2][J+2];
    double fluHg0x[I+2][J+2][K+2], fluHg0y[I+2][J+2][K+2], fluHg0z[I+2][J+2][K+2], fluHgIIx[I+2][J+2][K+2], fluHgIIy[I+2][J+2][K+2], fluHgIIz[I+2][J+2][K+2];
    double fluMMHgx[I+2][J+2][K+2], fluMMHgy[I+2][J+2][K+2], fluMMHgz[I+2][J+2][K+2], fluSPMx[I+2][J+2][K+2], fluSPMy[I+2][J+2][K+2], fluSPMz[I+2][J+2][K+2];
    double flub1x[I+2][J+2][K+2], flub1y[I+2][J+2][K+2], flub1z[I+2][J+2][K+2], fluRx[I+2][J+2][K+2], fluRy[I+2][J+2][K+2], fluRz[I+2][J+2][K+2];
    double kphupII[I+2][J+2][K+2], kphexII, kphupMM[I+2][J+2][K+2], kphexMM, kphgr;
    double PHgIIexts26, PMMHgexts26, PHgexts26;
    double PHgIIextm26, PMMHgextm26, PHgextm26;
    double PHgIIextb26, PMMHgextb26, PHgextb26;
    double PHgIIexts27, PMMHgexts27, PHgexts27;
    double PHgIIextm27, PMMHgextm27, PHgextm27;
    double PHgIIextb27, PMMHgextb27, PHgextb27;
    double TotfluHg0xlev, fluHg0xlev, TotfluHgIIxlev, fluHgIIxlev, TotfluMMHgxlev, fluMMHgxlev, fluTHgxlev, Totlev;
    double TotfluHg0xysci, fluHg0xsci, fluHg0ysci, TotfluHgIIxysci, fluHgIIxsci, fluHgIIysci, TotfluMMHgxysci, fluMMHgxsci, fluMMHgysci, fluTHgxsci, fluTHgysci, Totsci;
    double fluHgIIzsed, fluMMHgzsed, fluHgIIzsedext1, fluHgIIzsedext2, fluHgIIzsedext3, fluMMHgzsedext1, fluMMHgzsedext2, fluMMHgzsedext3;
    double fluHgIIzbur, fluHgIIzburext1, fluHgIIzburext2, fluHgIIzburext3;
    double fluMMHgzbur, fluMMHgzburext1, fluMMHgzburext2, fluMMHgzburext3;
    double fluxHg0zatm, fluxHg0zdep, fluxHgIIzdep, fluxMMHgzdep, fluxHg0zatmext1, fluxHg0zdepext1, fluxHgIIzdepext1, fluxMMHgzdepext1;
    double fluxHg0zatmext2, fluxHg0zdepext2, fluxHgIIzdepext2, fluxMMHgzdepext2, fluxHg0zatmext3, fluxHg0zdepext3, fluxHgIIzdepext3, fluxMMHgzdepext3;
    double fluxSPMzdep, fluxSPMzdepext1, fluxSPMzdepext2, fluxSPMzdepext3;
    double TotfluHgIIzsed, TotfluMMHgzsed, TotfluHgIIzsedext1, TotfluHgIIzsedext2, TotfluHgIIzsedext3, TotfluMMHgzsedext1, TotfluMMHgzsedext2, TotfluMMHgzsedext3;
    double TotHgIIsed, TotMMHgsed, TotHgsed, TotSIISPM, TotSMMSPM, TotSIIDOM, TotSMMDOM;
    double TotHgIIbur, TotfluHgIIzbur, TotfluHgIIzburext1, TotfluHgIIzburext2, TotfluHgIIzburext3;
    double TotMMHgbur, TotfluMMHgzbur, TotfluMMHgzburext1, TotfluMMHgzburext2, TotfluMMHgzburext3;
    double TotfluHg0atm, TotfluHg0zatm, TotfluHg0zatmext1, TotfluHg0zatmext2, TotfluHg0zatmext3;
    double TotfluHg0dep, TotfluHg0zdep, TotfluHg0zdepext1, TotfluHg0zdepext2, TotfluHg0zdepext3;
    double TotfluHgIIdep, TotfluHgIIzdep, TotfluHgIIzdepext1, TotfluHgIIzdepext2, TotfluHgIIzdepext3;
    double TotfluSPMdep, TotfluSPMzdep, TotfluSPMzdepext1, TotfluSPMzdepext2, TotfluSPMzdepext3;
    double TotfluMMHgdep, TotfluMMHgzdep, TotfluMMHgzdepext1, TotfluMMHgzdepext2, TotfluMMHgzdepext3;
    double TotfluHgdep, TotHgbur;
    double peratio, Hggas, OCRR, k3, k4, dt;
    
    char *tmp,buf[20],buf1[50]; 

	
    value1= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        value1[p]=(double*)malloc(2 * sizeof(double));
    } 

    value2= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        value2[p]=(double*)malloc(2 * sizeof(double));
    } 

    value3= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        value3[p]=(double*)malloc(2 * sizeof(double));
    }    

    value5= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        value5[p]=(double*)malloc(2 * sizeof(double));
    } 

    ero= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        ero[p]=(double*)malloc(1 * sizeof(double));
    }
    
    ero2= (double**)malloc(180 * sizeof(double*));
    for (p=1; p<=180; p++){
        ero2[p]=(double*)malloc(1 * sizeof(double));
    }

	if((fb1=fopen("Phyto_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

	if((fct=fopen("Chlor_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

	if((fR=fopen("Nutrient_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

	if((fI=fopen("Light_int.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}


	if((fHg0=fopen("Hg0_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

	if((fHgII=fopen("HgII_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

	if((fMMHg=fopen("MMHg_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

	if((fDHg=fopen("DHg_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

	if((fTHg=fopen("THg_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

	/*if((fSPM=fopen("SPM_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}*/

	if((fHgIIpw=fopen("HgIIpw_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

    if((fMMHgpw=fopen("MMHgpw_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fTHgsed=fopen("THgsed.txt", "wb+"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  
  	if((ftotdep=fopen("Totdep.txt", "wb+"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fHgIIfluxsed=fopen("FluxHgIIsed.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

    if((fMMHgfluxsed=fopen("FluxMMHgsed.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  		
  	if((fHg0fluxatm=fopen("FluxHg0atm.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fHg0fluxdep=fopen("FluxHg0dep.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fHgIIfluxdep=fopen("FluxHgIIdep.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fMMHgfluxdep=fopen("FluxMMHgdep.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fu=fopen("mass-balance.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fRelease=fopen("R_time.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fOutflow=fopen("O-I_time.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fEvasion=fopen("V-AD_time.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fRecycled=fopen("D_time.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

    if((fP=fopen("Mercury-Phyto.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

    if((fZ=fopen("Mercury-Zoo.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

    if((fFi=fopen("Mercury-Fish.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fZtmean=fopen("Temp_mean_mercury_fish.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fFitmean=fopen("Temp_mean_mercury_fish.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fFisptmean=fopen("Spatio-temp_mean_mercury_fish.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
	if((fRin1=fopen("Rin1.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fSPMin1=fopen("SPMin1.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin1=fopen("SPOMin1.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
 
	if((fRin2=fopen("Rin2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fSPMin2=fopen("SPMin2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fSPOMin2=fopen("SPOMin2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fRin3=fopen("Rin3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fSPMin3=fopen("SPMin3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin3=fopen("SPOMin3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fRin4=fopen("Rin4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPMin4=fopen("SPMin4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin4=fopen("SPOMin4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fRin5=fopen("Rin5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPMin5=fopen("SPMin5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin5=fopen("SPOMin5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fRin6=fopen("Rin6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPMin6=fopen("SPMin6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin6=fopen("SPOMin6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fTHgsedin=fopen("THgsedin.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin2=fopen("THgsedin2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin3=fopen("THgsedin3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin4=fopen("THgsedin4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin5=fopen("THgsedin5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin6=fopen("THgsedin6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin7=fopen("THgsedin7.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin8=fopen("THgsedin8.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin9=fopen("THgsedin9.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin10=fopen("THgsedin10.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSWsed=fopen("SWsed.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fTOCsed=fopen("TOCsed.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fporsed=fopen("porsed.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed2=fopen("porsed2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed3=fopen("porsed3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed4=fopen("porsed4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed5=fopen("porsed5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed6=fopen("porsed6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed7=fopen("porsed7.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed8=fopen("porsed8.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed9=fopen("porsed9.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed10=fopen("porsed10.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fIin=fopen("Iin.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTatm=fopen("Tatm.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fPrec=fopen("Prec.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fHggas=fopen("Hg0gas.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fHgIIatm=fopen("HgIIatm.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

  	
    if((fv5=fopen("newlev_0_5.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
	
	if((fv10=fopen("newlev_5_10.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
 
	if((fv20=fopen("newlev_10_20.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
		
	if((fv30=fopen("newlev_20_30.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}

    if((fero=fopen("erosion.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
	
	if((fero2=fopen("erosion2.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
	
	dt=(double) tempo/M; // h
	Iin=339.83; // micromol photons/(m^2*sec)
	Tatm=13.17; // °C
	Pr=0.00268; // m
	HgIIatm=21000.000; //ng/m^3
	Hggas=1.59; // ng/m^3
	idt=(int) 3*pow(dt,-1);
	idtb=12;
	
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x

     fscanf(fRin1,"%lf", &Rin1[i][j]); 
     fscanf(fSPMin1,"%lf", &SPMin1[i][j]); 
     fscanf(fSPOMin1,"%lf", &SPOMin1[i][j]); 
                
     Rini[i][j][1]=Rin1[i][j];
     SPM[i][j][1]=SPMin1[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][1]=SPOMin1[i][j]*pow(10.0,-6.0); //Kg/l
     
     } 
  } 
  
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin2,"%lf", &Rin2[i][j]); 
     fscanf(fSPMin2,"%lf", &SPMin2[i][j]); 
     fscanf(fSPOMin2,"%lf", &SPOMin2[i][j]);
                
     Rini[i][j][2]=Rin2[i][j];
     SPM[i][j][2]=SPMin2[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][2]=SPOMin2[i][j]*pow(10.0,-6.0); //Kg/l
     
     } 
  }
  
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin3,"%lf", &Rin3[i][j]); 
     fscanf(fSPMin3,"%lf", &SPMin3[i][j]); 
     fscanf(fSPOMin3,"%lf", &SPOMin3[i][j]);

     Rini[i][j][3]=Rin3[i][j]; 
     SPM[i][j][3]=SPMin3[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][3]=SPOMin3[i][j]*pow(10.0,-6.0); //Kg/l     
     
     } 
  }                       
               
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin4,"%lf", &Rin4[i][j]);
     fscanf(fSPMin4,"%lf", &SPMin4[i][j]); 
     fscanf(fSPOMin4,"%lf", &SPOMin4[i][j]); 

     Rini[i][j][4]=Rin4[i][j];  
     SPM[i][j][4]=SPMin4[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][4]=SPOMin4[i][j]*pow(10.0,-6.0); //Kg/l       
     
     } 
  }           
  
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin5,"%lf", &Rin5[i][j]); 
     fscanf(fSPMin5,"%lf", &SPMin5[i][j]); 
     fscanf(fSPOMin5,"%lf", &SPOMin5[i][j]); 

     Rini[i][j][5]=Rin5[i][j]; 
     SPM[i][j][5]=SPMin5[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][5]=SPOMin5[i][j]*pow(10.0,-6.0); //Kg/l        
     
     } 
  }            
                      
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin6,"%lf", &Rin6[i][j]); 
     fscanf(fSPMin6,"%lf", &SPMin6[i][j]); 
     fscanf(fSPOMin6,"%lf", &SPOMin6[i][j]); 

     Rini[i][j][6]=Rin6[i][j]; 
     SPM[i][j][6]=SPMin6[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][6]=SPOMin6[i][j]*pow(10.0,-6.0); //Kg/l              
     
     } 
  } 
  
  
  for(i=0; i<=I; i++){ // rispetto allo spazio y 
     for(k=0; k<=K; k++){ // rispetto allo spazio x
                     
     Rini[i][0][k]=0.000000;         
     b1[i][0][k]=0.000000; 
     Hg0[i][0][k]=0.000000; 
     HgII[i][0][k]=0.000000;  
     MMHg[i][0][k]=0.000000;
     DHg[i][0][k]=0.000000;
     SPM[i][0][k]=0.000000;
     SPOM[i][0][k]=0.000000;
     R[i][0][k]=0.000000;
     vxc[i][0][k]=0.000000;
     vyc[i][0][k]=0.000000;
     
     } 
  } 
  
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(k=0; k<=K; k++){ // rispetto allo spazio x
                     
     Rini[0][j][k]=0.000000;
     b1[0][j][k]=0.000000;
     Hg0[0][j][k]=0.000000;
     HgII[0][j][k]=0.000000; 
     MMHg[0][j][k]=0.000000;
     DHg[0][j][k]=0.000000;
     SPM[0][j][k]=0.000000;
     SPOM[0][j][k]=0.000000;
     R[0][j][k]=0.000000; 
     vxc[0][j][k]=0.000000;
     vyc[0][j][k]=0.000000;   
     
     } 
  } 
 
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fTHgsedin,"%lf", &THgsedin[i][j]); 
     fscanf(fTHgsedin2,"%lf", &THgsedin2[i][j]); 
     fscanf(fTHgsedin3,"%lf", &THgsedin3[i][j]); 
     fscanf(fTHgsedin4,"%lf", &THgsedin4[i][j]); 
     fscanf(fTHgsedin5,"%lf", &THgsedin5[i][j]); 
     fscanf(fTHgsedin6,"%lf", &THgsedin6[i][j]); 
     fscanf(fTHgsedin7,"%lf", &THgsedin7[i][j]); 
     fscanf(fTHgsedin8,"%lf", &THgsedin8[i][j]); 
     fscanf(fTHgsedin9,"%lf", &THgsedin9[i][j]); 
     fscanf(fTHgsedin10,"%lf", &THgsedin10[i][j]); 
     fscanf(fSWsed,"%lf", &SWsedin[i][j]);
     fscanf(fTOCsed,"%lf", &TOCsedin[i][j]); 
     fscanf(fporsed,"%lf", &porsedin[i][j]);
     fscanf(fporsed2,"%lf", &porsedin2[i][j]);
     fscanf(fporsed3,"%lf", &porsedin3[i][j]);
     fscanf(fporsed4,"%lf", &porsedin4[i][j]);
     fscanf(fporsed5,"%lf", &porsedin5[i][j]);
     fscanf(fporsed6,"%lf", &porsedin6[i][j]);
     fscanf(fporsed7,"%lf", &porsedin7[i][j]);
     fscanf(fporsed8,"%lf", &porsedin8[i][j]);
     fscanf(fporsed9,"%lf", &porsedin9[i][j]);
     fscanf(fporsed10,"%lf", &porsedin10[i][j]);
     
     THgsed[i][j][1]=THgsedin[i][j];
     THgsed[i][j][2]=THgsedin2[i][j]; 
     THgsed[i][j][3]=THgsedin3[i][j]; 
     THgsed[i][j][4]=THgsedin4[i][j];
     THgsed[i][j][5]=THgsedin5[i][j]; 
     THgsed[i][j][6]=THgsedin6[i][j]; 
     THgsed[i][j][7]=THgsedin7[i][j];
     THgsed[i][j][8]=THgsedin8[i][j]; 
     THgsed[i][j][9]=THgsedin9[i][j]; 
     THgsed[i][j][10]=THgsedin10[i][j]; 
     SWsed[i][j]=SWsedin[i][j];
     TOCsed[i][j]=TOCsedin[i][j];
     porsed[i][j][1]=porsedin[i][j]; 
     porsed[i][j][2]=porsedin2[i][j]; 
     porsed[i][j][3]=porsedin3[i][j]; 
     porsed[i][j][4]=porsedin4[i][j]; 
     porsed[i][j][5]=porsedin5[i][j]; 
     porsed[i][j][6]=porsedin6[i][j]; 
     porsed[i][j][7]=porsedin7[i][j]; 
     porsed[i][j][8]=porsedin8[i][j]; 
     porsed[i][j][9]=porsedin9[i][j]; 
     porsed[i][j][10]=porsedin10[i][j]; 
     
     } 
  } 

  kphexII=(pow(Wp1,-kp)/(rowat+rolip))*(1.0/(pcap*pow(10.0,logkdII))); // 1/d
  kphexMM=(pow(Wp1,-kp)/(rowat+rolip))*(1.0/(pcap*pow(10.0,logkdMM))); //1/d
  kphgr=ag*pow(Vpce1,-bg); // 1/d
  PHgIIexts27=Wp1*VFCII*0.794*DHgexts27*pow(10.0,-12.0); //  microg
  PMMHgexts27=Wp1*VFCMM*0.006*DHgexts27*pow(10.0,-12.0); //  microg
  PHgexts27=PHgIIexts27+PMMHgexts27; //  microg
  PHgIIextm27=Wp1*VFCII*0.794*DHgextm27*pow(10.0,-12.0); //  microg
  PMMHgextm27=Wp1*VFCMM*0.006*DHgextm27*pow(10.0,-12.0); //  microg
  PHgextm27=PHgIIextm27+PMMHgextm27; //  microg
  PHgIIextb27=Wp1*VFCII*0.794*DHgextb27*pow(10.0,-12.0); //  microg
  PMMHgextb27=Wp1*VFCMM*0.006*DHgextb27*pow(10.0,-12.0); //  microg
  PHgextb27=PHgIIextb27+PMMHgextb27; //  microg
  PHgIIexts26=Wp1*VFCII*0.794*DHgexts26*pow(10.0,-12.0); //  microg
  PMMHgexts26=Wp1*VFCMM*0.006*DHgexts26*pow(10.0,-12.0); //  microg
  PHgexts26=PHgIIexts26+PMMHgexts26; //  microg
  PHgIIextm26=Wp1*VFCII*0.794*DHgextm26*pow(10.0,-12.0); //  microg
  PMMHgextm26=Wp1*VFCMM*0.006*DHgextm26*pow(10.0,-12.0); //  microg
  PHgextm26=PHgIIextm26+PMMHgextm26; //  microg
  PHgIIextb26=Wp1*VFCII*0.794*DHgextb26*pow(10.0,-12.0); //  microg
  PMMHgextb26=Wp1*VFCMM*0.006*DHgextb26*pow(10.0,-12.0); //  microg
  PHgextb26=PHgIIextb26+PMMHgextb26; //  microg
  
  Wfish=aWf*pow(Lfish,bWf)*pow(10.0,-3.0); // Kg
  kfurMM=pow(Wfish,-1.0*kal)/(rowat+(rolip/pow(10.0,logKow))); // l/Kg*d
  kfexrMM=kfurMM/pow(10.0,logBCFMM); // 1/d
  kfgr=1.0/tfish; // 1/d
  lambmet=(log(2.0)/hlmet)*pow((0.01/Wfish),-1.0*kal)*exp(0.01*(15.0-Twat)); // 1/d
  kfin=0.002*pow(Wfish,-1.0*kal)*(AssFoodII/(1.0-AssFoodII)); // 1/d
  plipfood=PrefPhy*plipPhy; // dimensionless (da modificare)
  kfinMM=(AssFoodMM/(1.0-AssFoodMM))*(1.0/(plipfood*(pow(10.0,logKow)-1.0)+1.0))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolip/pow(10.0,logKow))+(1.0/(plipfood*pow(10.0,logKow)*(1.0-AssFoodMM)*gamfood)))); // 1/d
  kfegr=kfin*((1.0-AssFoodII)/AssFoodII); // 1/d
  kfegrMM=(1.0/(plipFish*(pow(10.0,logKow)-1.0)+1.0))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolip/pow(10.0,logKow))+(1.0/(plipfood*pow(10.0,logKow)*(1.0-AssFoodMM)*gamfood)))); // 1/d
  
  for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
     
        pcarsed[i][j]=0.01*TOCsed[i][j]; // dimensionless
        kfinMMsed[i][j]=(AssFoodMM/(1.0-AssFoodMM))*(1.0/(pcarsed[i][j]*(pow(10.0,logKoc)-1.0)+1.0))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolip/pow(10.0,logKow))+(1.0/(pcarsed[i][j]*pow(10.0,logKoc)*(1.0-AssFoodMM)*gamfood)))); // 1/d
        kfegrMMsed[i][j]=(1.0/(plipFish*(pow(10.0,logKow)-1.0)+1.0))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolip/pow(10.0,logKow))+(1.0/(pcarsed[i][j]*pow(10.0,logKoc)*(1.0-AssFoodMM)*gamfood)))); // 1/d
     
        for(k=1; k<=K; k++){ // rispetto allo spazio z
        
        if(Rini[i][j][k]>=Rin){             
            DHg[i][j][k]=dlHg; // ng/l or microg/m^3 
            THg[i][j][k]=dlHg; // ng/l or microg/m^3 
        }
        else{
            DHg[i][j][k]=0.0; // ng/l or microg/m^3 
            THg[i][j][k]=0.0; // ng/l or microg/m^3 
        } 
        
        Hg0[i][j][k]=0.2*DHg[i][j][k]; // ng/l or microg/m^3
        HgII[i][j][k]=0.794*DHg[i][j][k]; // ng/l or microg/m^3
        MMHg[i][j][k]=0.006*DHg[i][j][k]; // ng/l or microg/m^3
        PHgII[i][j][k]=Wp1*VFCII*HgII[i][j][k]*pow(10.0,-12.0); //  microg
        PMMHg[i][j][k]=Wp1*VFCMM*MMHg[i][j][k]*pow(10.0,-12.0); //  microg
        PHg[i][j][k]=PHgII[i][j][k]+PMMHg[i][j][k]; //  microg
        R[i][j][k]=Rini[i][j][k];
        
        if(Rini[i][j][k]==Rbot){            
           
           if(HgII[i][j][k]<=0.000000){
				logBCFII[i][j]=0.0;
           }
           else{
               logBCFII[i][j]=aBCF+bBCF*log10(HgII[i][j][k]*pow(10.0,-3.0)); // l/Kg
           }    
       
           DietzooHgII[i][j]=1.0*(PHgII[i][j][k]/Wp1)*pow(10.0,9.0); // microg/Kg
           DietzooMMHg[i][j]=1.0*(PMMHg[i][j][k]/Wp1)*pow(10.0,9.0); // microg/Kg               
           ZHgIIre[i][j]=(Wzoo*kzurII*HgII[i][j][k]*pow(10.0,-3.0))/(kzexrII+kzgr); // microg
           ZHgIIGIT[i][j]=(Wzoo*AssFoodzooII*kzinII*DietzooHgII[i][j]*pow(10.0,-3.0))/(kzegII+kzgr);  // microg
           ZMMHgre[i][j]=(Wzoo*kzurMM*MMHg[i][j][k]*pow(10.0,-3.0))/(kzexrMM+kzgr); // microg
           ZMMHgGIT[i][j]=(Wzoo*AssFoodzooMM*kzinMM*DietzooMMHg[i][j]*pow(10.0,-3.0))/(kzegMM+kzgr);  // microg
           
           if(ZHgIIre[i][j]<=0.000000){
				ZHgIIre[i][j]=0.0;
           } 
	   
	       if(ZMMHgre[i][j]<=0.000000){
				ZMMHgre[i][j]=0.0;
	       }
           
           if(ZHgIIGIT[i][j]<=0.000000){
				ZHgIIGIT[i][j]=0.0;
           } 
	   
	       if(ZMMHgGIT[i][j]<=0.000000){
				ZMMHgGIT[i][j]=0.0;
	       }
           
           ZHgII[i][j]=(ZHgIIre[i][j]+ZHgIIGIT[i][j])*(1.0/Wzoo);  // microg/g
           ZMMHg[i][j]=(ZMMHgre[i][j]+ZMMHgGIT[i][j])*(1.0/Wzoo);  // microg/g
           
           if(ZHgII[i][j]<=0.000000){
				ZHgII[i][j]=0.0;
           } 
	   
	       if(ZMMHg[i][j]<=0.000000){
				ZMMHg[i][j]=0.0;
	       } 
     
           kfurII[i][j]=0.002*pow(Wfish,-1.0*kal)*pow(10.0,logBCFII[i][j]); // l/Kg*d
           kfexrII[i][j]=kfurII[i][j]/pow(10.0,logBCFII[i][j]); // 1/d
           DietHgII[i][j]=PrefZoo*(ZHgII[i][j])*pow(10.0,3.0)+Prefsed*((1.0-kMM)*THgsed[i][j][1])*pow(10.0,3.0); // microg/Kg
           DietMMHg[i][j]=PrefZoo*(ZMMHg[i][j])*pow(10.0,3.0)+Prefsed*(kMM*THgsed[i][j][1])*pow(10.0,3.0); // microg/Kg               
           FiHgIIre[i][j]=(Wfish*kfurII[i][j]*HgII[i][j][k]*pow(10.0,-3.0))/(kfexrII[i][j]+kfgr); // microg
           FiHgIIGIT[i][j]=(Wfish*kfin*DietHgII[i][j])/(kfegr+kfgr);  // microg
           FiMMHgre[i][j]=(Wfish*kfurMM*MMHg[i][j][k]*pow(10.0,-3.0))/(kfexrMM+kfgr+lambmet); // microg
           FiMMHgGIT[i][j]=(Wfish*kfinMM*DietMMHg[i][j])/(kfegrMM+kfgr+lambmet);   // microg 
           FiMMHgGITdet[i][j]=(Wfish*kfinMMsed[i][j]*DietMMHg[i][j])/(kfegrMMsed[i][j]+kfgr+lambmet);   // microg 
           
           if(FiHgIIre[i][j]<=0.000000){
				FiHgIIre[i][j]=0.0;
           } 
	   
	       if(FiMMHgre[i][j]<=0.000000){
				FiMMHgre[i][j]=0.0;
	       }
           
           if(FiHgIIGIT[i][j]<=0.000000){
				FiHgIIGIT[i][j]=0.0;
           } 
	   
	       if(FiMMHgGIT[i][j]<=0.000000){
				FiMMHgGIT[i][j]=0.0;
	       }
	   
	       if(FiMMHgGITdet[i][j]<=0.000000){
				FiMMHgGITdet[i][j]=0.0;
	       }
           
           FiHgII[i][j]=(FiHgIIre[i][j]+FiHgIIGIT[i][j])*pow(10.0,-3.0)*(1.0/Wfish);  // mg/Kg
           FiMMHg[i][j]=(FiMMHgre[i][j]+FiMMHgGIT[i][j]+FiMMHgGITdet[i][j])*pow(10.0,-3.0)*(1.0/Wfish);  // mg/Kg
           
           if(FiHgII[i][j]<=0.000000){
				FiHgII[i][j]=0.0;
           } 
	   
	       if(FiMMHg[i][j]<=0.000000){
				FiMMHg[i][j]=0.0;
	       } 
           
       }
        
        
        if(Hg0[i][j][k]<=0.000000){
				Hg0[i][j][k]=0.0;
	    }
			
        if(HgII[i][j][k]<=0.000000){
				HgII[i][j][k]=0.0;
        }
			
        if(MMHg[i][j][k]<=0.000000){
				MMHg[i][j][k]=0.0;
        }
     
        if(PHgII[i][j][k]<=0.000000){
				PHgII[i][j][k]=0.0;
        }
		   
        if(PMMHg[i][j][k]<=0.000000){
				PMMHg[i][j][k]=0.0;
        }
			
        if(PHg[i][j][k]<=0.000000){
				PHg[i][j][k]=0.0;
        }

	  }

     } 
  }      
  
  for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
        for(k=1; k<=K; k++){ // rispetto allo spazio z     
        
        if(Rini[i][j][k]>=Rin){
           
           vz[i][j][k]=vz0;
           b1[i][j][k]=B1; // cell/m^3
           forg[i][j][k]=SPOM[i][j][k]/SPM[i][j][k];
           SPIM[i][j][k]=(1.0-forg[i][j][k])*SPM[i][j][k]; //  Kg/l
           chla1[i][j][k]=b1[i][j][k]*exp((((k-1)*dz)+33.72)/19.57)*pow(10.0,-12.0);  // mg/m^3
           chlatot[i][j][k]= chla1[i][j][k]+chla2;  // mg/m^3
           SIIDOM[i][j][k]=lambda1*m1*b1[i][j][k]*PHgII[i][j][k]; // microg/(m^3*h)
           SMMDOM[i][j][k]=lambda1*m1*b1[i][j][k]*PMMHg[i][j][k]; // microg/(m^3*h)
           SLSPM[i][j][k]=(m1*b1[i][j][k]*Wp1*(1.0-lambda1)); // microg/(m^3*h)
           
		   if(SIIDOM[i][j][k]<=0.000000){
				SIIDOM[i][j][k]=0.0;
			}
		   
		   if(SMMDOM[i][j][k]<=0.000000){
				SMMDOM[i][j][k]=0.0;
			}
		   
		   if(SLSPM[i][j][k]<=0.000000){
				SLSPM[i][j][k]=0.0;
			}
		   
		   if(chla1[i][j][k]<=0.000000){
				chla1[i][j][k]=0.0;
			}
		   
           if(chlatot[i][j][k]<=0.000000){
				chlatot[i][j][k]=0.0;
			}
           
           
           peratio=-0.0081*Tatm+0.0806*log(chlas)+0.426; //dimensionless
           OCRR=(NPP/(12.011*75.0))*(1.0-peratio); // mol/m^3 *h
           k3=k3bio*OCRR; // h
           k4=k4bio*OCRR; //h
           
           if(k==1){
               SIISPM[i][j][k]=NPP*peratio*(kD0/forg[i][j][k])*pow(10,-6.0)*(HgII[i][j][k]/(dz/2.0));
               SMMSPM[i][j][k]=NPP*peratio*(kD0/forg[i][j][k])*pow(10,-6.0)*(MMHg[i][j][k]/(dz/2.0));
           }
           else{
               SIISPM[i][j][k]=NPP*peratio*(kD0/forg[i][j][k])*pow(10,-6.0)*((HgII[i][j][k]-HgII[i][j][k-1])/dz);
               SMMSPM[i][j][k]=NPP*peratio*(kD0/forg[i][j][k])*pow(10,-6.0)*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz);
           }
                     
           if(k==1){
              sommab1[i][j]=chla1[i][j][k];
              sommab2[i][j]=chla2;
              It[i][j][k]=Iin;
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           else{
              sommab1[i][j] += chla1[i][j][k];
              sommab2[i][j] += chla2;
              It[i][j][k]=Iin*exp(-(abg*(k-1)+(a2*(2*sommab2[i][j]-2*chla2)/2)+(a1*(2*sommab1[i][j]-chla1[i][j][k]-chla1[i][j][1])/2))*dz);
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           
           if(It[i][j][k]<=0.000000){
				It[i][j][k]=0.0;
			}
           
           F1I[i][j][k]=(r1*It[i][j][k])/(KI1+It[i][j][k]);
           F1R[i][j][k]=(r1*R[i][j][k])/(KR1+R[i][j][k]);
  
           if(F1I[i][j][k]>F1R[i][j][k]){
              G1[i][j][k]=F1R[i][j][k]-m1;
           }
           else{
              G1[i][j][k]=F1I[i][j][k]-m1;
           } 
              
        }	
        else{
        
           forg[i][j][k]=0.0; // in Kg/l
           SPIM[i][j][k]=0.0; // in Kg/l
           b1[i][j][k]=0.0;  // cell/m^3
           chla1[i][j][k]=0.0; // mg/m^3
           chlatot[i][j][k]=0.0; // mg/m^3
           SIIDOM[i][j][k]=0.0; // microg/(m^3*h)
           SMMDOM[i][j][k]=0.0; // microg/(m^3*h)
           SLSPM[i][j][k]=0.0; // microg/(m^3*h)
           vz[i][j][k]=0.0;
           
           if(k==1){
              It[i][j][k]=Iin;
		      k1[i][j][k]=0.0;
	          k2[i][j][k]=0.0;
           }
           else{
              It[i][j][k]=0.0;
		      k1[i][j][k]=0.0;
		      k2[i][j][k]=0.0;
           }
           
           F1I[i][j][k]=0.0;
           F1R[i][j][k]=0.0;
           G1[i][j][k]=0.0;
           
        }
         
        } 
     } 
  }  
  
  
  for(j=1; j<=J; j++){
     for(k=1; k<=K; k++){
     
     b1[I+1][j][k]=B1ext;
     R[I+1][j][k]=Rin;
     Hg0[I+1][j][k]=0.2*DHgexts27;
     HgII[I+1][j][k]=0.794*DHgexts27;
     MMHg[I+1][j][k]=0.006*DHgexts27;
     SPM[I+1][j][k]=SPMexts27;
                 
     } 
  }  
  
  for(i=1; i<=I; i++){
     for(k=1; k<=K; k++){
     
     b1[i][J+1][k]=B1ext;
     R[i][J+1][k]=Rin;
     Hg0[i][J+1][k]=0.2*DHgexts26;
     HgII[i][J+1][k]=0.794*DHgexts26;
     MMHg[i][J+1][k]=0.006*DHgexts26;
     SPM[i][J+1][k]=SPMexts26;
                 
     } 
  } 
  
  
for(i=1; i<=I; i++){
  for(j=1; j<=J; j++){
           
    if(Rini[i][j][1]>=Rin){
                                             
     MTCwaw[i][j]=(0.108*pow(uwind,1.64)*pow((PMCO2/PMHg0),0.25))/(24.0); // m/h 
     MTCwag[i][j]=(864.0*(0.2*uwind+0.3)*pow((PMH2O/PMHg0),0.3))/(24.0); // m/h 
     MTCwa[i][j]=(MTCwaw[i][j]*MTCwag[i][j])/(MTCwaw[i][j]+H1*MTCwag[i][j]); // m/h 
     MTCIIsw[i][j]=(Dwin*pow(porsed[i][j][1],(4.0/3.0)))/(delsed+delw*pow(porsed[i][j][1],(4.0/3.0))); // m/h
     MTCMMsw[i][j]=(Dwor*pow(porsed[i][j][1],(4.0/3.0)))/(delsedMM+delw*pow(porsed[i][j][1],(4.0/3.0))); // m/h
     
     }
     else{
     
     MTCwaw[i][j]=0.0; // m/h 
     MTCwag[i][j]=0.0; // m/h 
     MTCwa[i][j]=0.0;  // m/h 
     MTCIIsw[i][j]=0.0; // m/h
     MTCMMsw[i][j]=0.0; // m/h
     
    }
    
    for(r=1; r<=RL; r++){
     
     if(Rini[i][j][1]>=Rin){
                                             
     Dinsed[i][j][r]=(Dwin*porsed[i][j][r])/(1.0-log(pow(porsed[i][j][r],2.0))); // m^2/h
     Dorsed[i][j][r]=(Dwor*porsed[i][j][r])/(1.0-log(pow(porsed[i][j][r],2.0))); // m^2/h
     HgIIpw[i][j][r]=(1.0-kMM)*(THgsed[i][j][r]/kDIIsed)*pow(10.0,6.0); // microg/m^3
     MMHgpw[i][j][r]=kMM*(THgsed[i][j][r]/kDMMsed)*pow(10.0,6.0); // microg/m^3
    
     }
     else{
     
     Dinsed[i][j][r]=0.0; // m^2/h
     Dorsed[i][j][r]=0.0; // m^2/h
     HgIIpw[i][j][r]=0.0; // microg/m^3
     MMHgpw[i][j][r]=0.0; // microg/m^3
     
     }
     
     THgsedold[i][j][r]=THgsed[i][j][r]; // mg/Kg

   } 
  } 
 }
  
    for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
        
				fprintf(ftotdep,"%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, Totdep[i][j]);
				fprintf(fZ,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, ZHgII[i][j], ZMMHg[i][j]);
				fprintf(fFi,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, FiHgII[i][j], FiMMHg[i][j]);
				
            
            for(r=1; r<=RL; r++){
                     
                fprintf(fHgIIpw,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, HgIIpw[i][j][r]);
                fprintf(fMMHgpw,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, MMHgpw[i][j][r]); 
                fprintf(fTHgsed,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, THgsed[i][j][r]);
                
            } 
            
            
            for(k=1; k<=K; k++){
            
				fprintf(fb1,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, b1[i][j][k]);
				fprintf(fct,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, chlatot[i][j][k]);
				fprintf(fR,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, R[i][j][k]);
				fprintf(fI,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, It[i][j][k]);
				fprintf(fHg0,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, Hg0[i][j][k]);
				fprintf(fHgII,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, HgII[i][j][k]);
				fprintf(fMMHg,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, MMHg[i][j][k]);
				fprintf(fDHg,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, DHg[i][j][k]);
				fprintf(fTHg,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, THg[i][j][k]);
				//fprintf(fSPM,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, SPM[i][j][k]*pow(10.0,6.0)); // SPM in mg/l
				fprintf(fP,"%f\t%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, PHgII[i][j][k], PMMHg[i][j][k]);
				
            }    
        }
    }
  
    for(i=1; i<=I; i++){
     for(j=1; j<=J; j++){
	  for(k=1; k<=K; k++){

        PHgIItmean[i][j][k]=0.0;
        PMMHgtmean[i][j][k]=0.0; 
        PHgIItmean2[i][j][k]=0.0;
        PMMHgtmean2[i][j][k]=0.0;     
       
	  } 

	    ZHgIItmean[i][j]=0.0;
        ZMMHgtmean[i][j]=0.0; 
        FiHgIItmean[i][j]=0.0;
        FiMMHgtmean[i][j]=0.0;
        ZHgIItmean2[i][j]=0.0;
        ZMMHgtmean2[i][j]=0.0; 
        FiHgIItmean2[i][j]=0.0;
        FiMMHgtmean2[i][j]=0.0;
   
        }
    }


   PHgIIsptmean=0.0;
   PMMHgsptmean=0.0;
   ZHgIIsptmean=0.0;
   ZMMHgsptmean=0.0;
   FiHgIIsptmean=0.0;
   FiMMHgsptmean=0.0;
   PHgIIsptmean2=0.0;
   PMMHgsptmean2=0.0;
   ZHgIIsptmean2=0.0;
   ZMMHgsptmean2=0.0;
   FiHgIIsptmean2=0.0;
   FiMMHgsptmean2=0.0;
   

for(n=1; n<=N; n++){ // rispetto all'anno n

  if(n==N-T){ 
	for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
	  for(k=1; k<=K; k++){

        PHgIItmean[i][j][k]=0.0;
        PMMHgtmean[i][j][k]=0.0; 
        PHgIItmean2[i][j][k]=0.0;
        PMMHgtmean2[i][j][k]=0.0;     
       
	  } 

	    ZHgIItmean[i][j]=0.0;
        ZMMHgtmean[i][j]=0.0; 
        FiHgIItmean[i][j]=0.0;
        FiMMHgtmean[i][j]=0.0;
        ZHgIItmean2[i][j]=0.0;
        ZMMHgtmean2[i][j]=0.0; 
        FiHgIItmean2[i][j]=0.0;
        FiMMHgtmean2[i][j]=0.0;
   
        }
    }
   }



    for(p=1; p<=P; p++){
           fscanf(fv5,"%lf\t%lf\n", &value1[p][1],&value1[p][2]); 
           fscanf(fv10,"%lf\t%lf\n", &value2[p][1],&value2[p][2]);
           fscanf(fv20,"%lf\t%lf\n", &value3[p][1],&value3[p][2]);
           fscanf(fv30,"%lf\t%lf\n", &value5[p][1],&value5[p][2]);
           fscanf(fero,"%lf\n", &ero[p][1]);    
    } 
    
    for(p=1; p<=180; p++){
    fscanf(fero2,"%lf\n", &ero2[p][1]);
    }
  
  for(p=1; p<=180; p++){                   
      for(j=1; j<=J; j++){ // rispetto allo spazio y 
         for(i=1; i<=I; i++){ // rispetto allo spazio x                
             if(p==i+I*(j-1)){  

                vxc[i][j][1]=3600.0*value1[p][1];
                vyc[i][j][1]=-3600.0*value1[p][2];
                vxc[i][j][2]=3600.0*value2[p][1];
                vyc[i][j][2]=-3600.0*value2[p][2];
                vxc[i][j][3]=3600.0*value3[p][1];
                vyc[i][j][3]=-3600.0*value3[p][2];
                vxc[i][j][4]=3600.0*value3[p][1];
                vyc[i][j][4]=-3600.0*value3[p][2];
                vxc[i][j][5]=3600.0*value5[p][1];
                vyc[i][j][5]=-3600.0*value5[p][2];
                vxc[i][j][6]=3600.0*value5[p][1];
                vyc[i][j][6]=-3600.0*value5[p][2];
                dep[i][j]=ero[p][1];
                Totdepold[i][j]=ero2[p][1];
             }
         }       
      }               
  }
    
  for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
        for(k=1; k<=K; k++){ // rispetto allo spazio z     

        vx[i][j][k]=0.5*(vxc[i-1][j][k]+vxc[i][j][k]);
        vy[i][j][k]=0.5*(vyc[i][j-1][k]+vyc[i][j][k]);
        vxold[i][j][k]=vx[i][j][k];
        vyold[i][j][k]=vy[i][j][k];

        }
         
        depold[i][j]=dep[i][j];   
        Totdep[i][j]=(n-1)*Totdepold[i][j];  
         
     }               
  }

    TotSIISPM = 0.0; // kmol
    TotSMMSPM = 0.0; // kmol  
    TotSIIDOM = 0.0; // kmol
    TotSMMDOM = 0.0; // kmol
    
    for(i=1; i<=I; i++){ // rispetto allo spazio x
        for(j=1; j<=J; j++){ // rispetto allo spazio y 
            for(k=1; k<=K; k++){ // rispetto allo spazio z     
        
            if(Rini[i][j][k]>=Rin){
            TotSIISPM += SIISPM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMHgII); // kmol
            TotSMMSPM += SMMSPM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMMMHg); // kmol 
            TotSIIDOM += SIIDOM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMHgII); // kmol
            TotSMMDOM += SMMDOM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMMMHg); // kmol
            }
            
            }       
        }               
    }

   TotfluHg0xlev=0.0; 
   TotfluHgIIxlev=0.0; 
   TotfluMMHgxlev=0.0; 
   Totlev=0.0; 
   
   TotfluHg0xysci=0.0; 
   TotfluHgIIxysci=0.0; 
   TotfluMMHgxysci=0.0; 
   Totsci=0.0; 
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluxHgIIsed[i][j] = MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*24.0-HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*24.0; // microg/m^2*d
               fluxMMHgsed[i][j] = MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*24.0-MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*24.0; // microg/m^2*d    
           } 
             
           }
       }
   }
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][1]>=Rin){
               fluxHg0atm[i][j] = -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10,3.0); // ng/m^2*h
               fluxHg0dep[i][j] = Hggas*(Pr/det); // ng/m^2*h
               fluxHgIIdep[i][j] = HgIIatm*(Pr/det); // ng/m^2*h  
               fluxMMHgdep[i][j] = MMHgatm*(Pr/det); // ng/m^2*h 
           }
           else{
               fluxHg0atm[i][j] = 0.0; // ng/m^2*h
               fluxHg0dep[i][j] = 0.0; // ng/m^2*h
               fluxHgIIdep[i][j] = 0.0; // ng/m^2*h  
               fluxMMHgdep[i][j] = 0.0; // ng/m^2*h
           }
            
           }
       }
   }
 
 if(n==1){ 
    for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
                 
        fprintf(fHgIIfluxsed,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxHgIIsed[i][j]);
        fprintf(fMMHgfluxsed,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxMMHgsed[i][j]); 
        fprintf(fHg0fluxatm,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxHg0atm[i][j]);
        fprintf(fHg0fluxdep,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxHg0dep[i][j]);
        fprintf(fHgIIfluxdep,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxHgIIdep[i][j]);
        fprintf(fMMHgfluxdep,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxMMHgdep[i][j]);
                  
        }
    }
 } 
    
    
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Queste variabili dipendono dalla forma del bacino%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    
    fluHgIIzsed=0.0;
    fluMMHgzsed=0.0;
    fluHgIIzbur=0.0;
    fluMMHgzbur=0.0;
    fluHgIIzsedext1=0.0;
    fluMMHgzsedext1=0.0;
    fluHgIIzburext1=0.0;
    fluMMHgzburext1=0.0;
    fluHgIIzsedext2=0.0;
    fluMMHgzsedext2=0.0;
    fluHgIIzburext2=0.0;
    fluMMHgzburext2=0.0;
    fluHgIIzsedext3=0.0;
    fluMMHgzsedext3=0.0;
    fluHgIIzburext3=0.0;
    fluMMHgzburext3=0.0;
    fluxHg0zatm=0.0;
    fluxHg0zdep=0.0;
    fluxHgIIzdep=0.0;
    fluxMMHgzdep=0.0;
    fluxSPMzdep=0.0;
    fluxHg0zatmext1=0.0;
    fluxHg0zdepext1=0.0;
    fluxHgIIzdepext1=0.0;
    fluxMMHgzdepext1=0.0;
    fluxSPMzdepext1=0.0;
    fluxHg0zatmext2=0.0;
    fluxHg0zdepext2=0.0;
    fluxHgIIzdepext2=0.0;
    fluxMMHgzdepext2=0.0;
    fluxSPMzdepext2=0.0;
    fluxHg0zatmext3=0.0;
    fluxHg0zdepext3=0.0;
    fluxHgIIzdepext3=0.0;
    fluxMMHgzdepext3=0.0;
    fluxSPMzdepext3=0.0;
   
   TotfluHgIIzsed = 0.0; 
   TotfluMMHgzsed = 0.0; 
   TotfluHgIIzbur = 0.0; 
   TotfluMMHgzbur = 0.0; 
   TotfluHgIIzsedext1 = 0.0; 
   TotfluMMHgzsedext1 = 0.0; 
   TotfluHgIIzburext1 = 0.0; 
   TotfluMMHgzburext1 = 0.0; 
   TotfluHgIIzsedext2 = 0.0; 
   TotfluMMHgzsedext2 = 0.0; 
   TotfluHgIIzburext2 = 0.0; 
   TotfluMMHgzburext2 = 0.0; 
   TotfluHgIIzsedext3 = 0.0; 
   TotfluMMHgzsedext3 = 0.0; 
   TotfluHgIIzburext3 = 0.0; 
   TotfluMMHgzburext3 = 0.0; 
   
   TotfluHg0zatm = 0.0; 
   TotfluHg0zdep = 0.0; 
   TotfluHgIIzdep = 0.0; 
   TotfluMMHgzdep = 0.0; 
   TotfluSPMzdep = 0.0; 
   TotfluHg0zatmext1 = 0.0; 
   TotfluHg0zdepext1 = 0.0; 
   TotfluHgIIzdepext1 = 0.0; 
   TotfluMMHgzdepext1 = 0.0; 
   TotfluSPMzdepext1 = 0.0; 
   TotfluHg0zatmext2 = 0.0; 
   TotfluHg0zdepext2 = 0.0; 
   TotfluHgIIzdepext2 = 0.0; 
   TotfluMMHgzdepext2 = 0.0; 
   TotfluSPMzdepext2 = 0.0; 
   TotfluHg0zatmext3 = 0.0; 
   TotfluHg0zdepext3 = 0.0; 
   TotfluHgIIzdepext3 = 0.0; 
   TotfluMMHgzdepext3 = 0.0; 
   TotfluSPMzdepext3 = 0.0; 
   
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    

  for(q=1; q<=Q; q++){
		   fscanf(fIin,"%lf\t%lf\n", &Iinin[q][1],&Iinin[q][2]); 
		   fscanf(fTatm,"%lf\t%lf\n", &Tatmin[q][1],&Tatmin[q][2]); 
		   fscanf(fPrec,"%lf\t%lf\n", &Prin[q][1],&Prin[q][2]); 
		   fscanf(fHgIIatm,"%lf\t%lf\n", &HgIIatmin[q][1],&HgIIatmin[q][2]);
		   fscanf(fHggas,"%lf\t%lf\n", &Hggasin[q][1],&Hggasin[q][2]);
  }

    
 for(m=1; m<=M; m++){ // rispetto al tempo t

     if(m%idt==0){  
                               
       for(p=181*(m/idt)+1; p<=181*(m/idt+1)-1; p++){                 
          for(j=1; j<=J; j++){ // rispetto allo spazio y 
             for(i=1; i<=I; i++){ // rispetto allo spazio x                
                if(p==181*(m/idt)+i+I*(j-1)){

                vxc[i][j][1]=3600.0*value1[p][1];
                vyc[i][j][1]=-3600.0*value1[p][2];
                vxc[i][j][2]=3600.0*value2[p][1];
                vyc[i][j][2]=-3600.0*value2[p][2];
                vxc[i][j][3]=3600.0*value3[p][1];
                vyc[i][j][3]=-3600.0*value3[p][2];
                vxc[i][j][4]=3600.0*value3[p][1];
                vyc[i][j][4]=-3600.0*value3[p][2];
                vxc[i][j][5]=3600.0*value5[p][1];
                vyc[i][j][5]=-3600.0*value5[p][2];
                vxc[i][j][6]=3600.0*value5[p][1];
                vyc[i][j][6]=-3600.0*value5[p][2];
                dep[i][j]=(ero[p][1]-ero[p-181][1])/3.0; //m/h
                     
                }    
             }       
          }              
       }     
       
       for(i=1; i<=I; i++){ // rispetto allo spazio x
           for(j=1; j<=J; j++){ // rispetto allo spazio y 
               for(k=1; k<=K; k++){ // rispetto allo spazio z     

               vx[i][j][k]=0.5*(vxc[i-1][j][k]+vxc[i][j][k]);
               vy[i][j][k]=0.5*(vyc[i][j-1][k]+vyc[i][j][k]);

               } 
                 
           }               
       }
       
                     
       }
       else{
            
           for(i=1; i<=I; i++){ // rispetto allo spazio x
              for(j=1; j<=J; j++){ // rispetto allo spazio y 
                  for(k=1; k<=K; k++){ // rispetto allo spazio
               
                  vx[i][j][k]=vxold[i][j][k];
                  vy[i][j][k]=vyold[i][j][k];

                  }

                  dep[i][j]=depold[i][j];
                  
                
              }
           }  
                       
       }
             
                
       for(i=1; i<=I; i++){ // rispetto allo spazio x
           for(j=1; j<=J; j++){ // rispetto allo spazio y 
               for(k=1; k<=K; k++){ // rispetto allo spazio
       
               vxold[i][j][k]=vx[i][j][k];
               vyold[i][j][k]=vy[i][j][k];
       
               }

               depold[i][j]=dep[i][j];
               Totdep[i][j]+= dep[i][j]*dt;
               
               
           }
       } 
        
      for(q=1; q<=Q; q++){
                        
			if((m/(idtb*((int) Iinin[q][1])))==1){
				Iin=Iinin[q][2];
			}
            
            if((m/(idtb*((int) Tatmin[q][1])))==1){
				Tatm=Tatmin[q][2];
			}	
   
            if((m/(idtb*((int) Prin[q][1])))==1){
				Pr=Prin[q][2];
			}

		if((m/(idtb*((int) HgIIatmin[q][1])))==1){
				HgIIatm=HgIIatmin[q][2];
			}

			
			if((m/(idtb*((int) Hggasin[q][1])))==1){
				Hggas=Hggasin[q][2];
			}
   
      }
     
   for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
       for(k=1; k<=K; k++){ // rispetto allo spazio z
     
        if(Rini[i][j][k]>=Rin){
           
           if(Rini[i-1][j][k]>=Rin && Rini[i][j-1][k]>=Rin && Rini[i][j][k-1]>=Rin){
                                     
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*((flub1x[i][j][k]+1.0*Dxx*((b1[i][j][k]-b1[i-1][j][k])/dx))/dx)-1.0*dt*((flub1y[i][j][k]+1.0*Dyy*((b1[i][j][k]-b1[i][j-1][k])/dy))/dy)-1.0*dt*((flub1z[i][j][k]+1.0*Dzz*((b1[i][j][k]-b1[i][j][k-1])/dz))/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3)*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*((fluHg0x[i][j][k]+1.0*Dxx*((Hg0[i][j][k]-Hg0[i-1][j][k])/dx))/dx)-1.0*dt*((fluHg0y[i][j][k]+1.0*Dyy*((Hg0[i][j][k]-Hg0[i][j-1][k])/dy))/dy)-1.0*dt*((fluHg0z[i][j][k]+1.0*Dzz*((Hg0[i][j][k]-Hg0[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3)*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*kmeth*HgII[i][j][k]*dt-1.0*dt*((fluHgIIx[i][j][k]+1.0*Dxx*((HgII[i][j][k]-HgII[i-1][j][k])/dx))/dx)-1.0*dt*((fluHgIIy[i][j][k]+1.0*Dyy*((HgII[i][j][k]-HgII[i][j-1][k])/dy))/dy)-1.0*dt*((fluHgIIz[i][j][k]+1.0*Dzz*((HgII[i][j][k]-HgII[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-1.0*dt*((fluMMHgx[i][j][k]+1.0*Dxx*((MMHg[i][j][k]-MMHg[i-1][j][k])/dx))/dx)-1.0*dt*((fluMMHgy[i][j][k]+1.0*Dyy*((MMHg[i][j][k]-MMHg[i][j-1][k])/dy))/dy)-1.0*dt*((fluMMHgz[i][j][k]+1.0*Dzz*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
         //  SPM[i][j][k]+= (SLSPM[i][j][k]+G1[i][j][k]*Wp1*b1[i][j][k])*pow(10.0,-12.0)*dt-1.0*dt*((fluSPMx[i][j][k]+1.0*Dxx*((SPM[i][j][k]-SPM[i-1][j][k])/dx))/dx)-1.0*dt*((fluSPMy[i][j][k]+1.0*Dyy*((SPM[i][j][k]-SPM[i][j-1][k])/dy))/dy)-1.0*dt*((fluSPMz[i][j][k]+1.0*Dzz*((SPM[i][j][k]-SPM[i][j][k-1])/dz))/dz); // Kg/l
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*((fluRx[i][j][k]+1.0*Dxx*((R[i][j][k]-R[i-1][j][k])/dx))/dx)-1.0*dt*((fluRy[i][j][k]+1.0*Dyy*((R[i][j][k]-R[i][j-1][k])/dy))/dy)-1.0*dt*((fluRz[i][j][k]+1.0*Dzz*((R[i][j][k]-R[i][j][k-1])/dz))/dz);
           } 
           
           }
           else if(Rini[i-1][j][k]>=Rin && Rini[i][j-1][k]>=Rin && Rini[i][j][k-1]<Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*((flub1x[i][j][k]+1.0*Dxx*((b1[i][j][k]-b1[i-1][j][k])/dx))/dx)-1.0*dt*((flub1y[i][j][k]+1.0*Dyy*((b1[i][j][k]-b1[i][j-1][k])/dy))/dy)-1.0*dt*(flub1z[i][j][k]/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3)*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*((fluHg0x[i][j][k]+1.0*Dxx*((Hg0[i][j][k]-Hg0[i-1][j][k])/dx))/dx)-1.0*dt*((fluHg0y[i][j][k]+1.0*Dyy*((Hg0[i][j][k]-Hg0[i][j-1][k])/dy))/dy)-1.0*dt*(fluHg0z[i][j][k]/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3)*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*kmeth*HgII[i][j][k]*dt-1.0*dt*((fluHgIIx[i][j][k]+1.0*Dxx*((HgII[i][j][k]-HgII[i-1][j][k])/dx))/dx)-1.0*dt*((fluHgIIy[i][j][k]+1.0*Dyy*((HgII[i][j][k]-HgII[i][j-1][k])/dy))/dy)-1.0*dt*(fluHgIIz[i][j][k]/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-1.0*dt*((fluMMHgx[i][j][k]+1.0*Dxx*((MMHg[i][j][k]-MMHg[i-1][j][k])/dx))/dx)-1.0*dt*((fluMMHgy[i][j][k]+1.0*Dyy*((MMHg[i][j][k]-MMHg[i][j-1][k])/dy))/dy)-1.0*dt*(fluMMHgz[i][j][k]/dz); // ng/l or microg/m^3
         //  SPM[i][j][k]+= (SLSPM[i][j][k]+G1[i][j][k]*Wp1*b1[i][j][k])*pow(10.0,-12.0)*dt-1.0*dt*((fluSPMx[i][j][k]+1.0*Dxx*((SPM[i][j][k]-SPM[i-1][j][k])/dx))/dx)-1.0*dt*((fluSPMy[i][j][k]+1.0*Dyy*((SPM[i][j][k]-SPM[i][j-1][k])/dy))/dy)-1.0*dt*(fluSPMz[i][j][k]/dz); // Kg/l
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*((fluRx[i][j][k]+1.0*Dxx*((R[i][j][k]-R[i-1][j][k])/dx))/dx)-1.0*dt*((fluRy[i][j][k]+1.0*Dyy*((R[i][j][k]-R[i][j-1][k])/dy))/dy)-1.0*dt*(fluRz[i][j][k]/dz);
           } 
			
           } 
           else if(Rini[i-1][j][k]>=Rin && Rini[i][j-1][k]<Rin && Rini[i][j][k-1]>=Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*((flub1x[i][j][k]+1.0*Dxx*((b1[i][j][k]-b1[i-1][j][k])/dx))/dx)-1.0*dt*(flub1y[i][j][k]/dy)-1.0*dt*((flub1z[i][j][k]+1.0*Dzz*((b1[i][j][k]-b1[i][j][k-1])/dz))/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3)*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*((fluHg0x[i][j][k]+1.0*Dxx*((Hg0[i][j][k]-Hg0[i-1][j][k])/dx))/dx)-1.0*dt*(fluHg0y[i][j][k]/dy)-1.0*dt*((fluHg0z[i][j][k]+1.0*Dzz*((Hg0[i][j][k]-Hg0[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3)*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*kmeth*HgII[i][j][k]*dt-1.0*dt*((fluHgIIx[i][j][k]+1.0*Dxx*((HgII[i][j][k]-HgII[i-1][j][k])/dx))/dx)-1.0*dt*(fluHgIIy[i][j][k]/dy)-1.0*dt*((fluHgIIz[i][j][k]+1.0*Dzz*((HgII[i][j][k]-HgII[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-1.0*dt*((fluMMHgx[i][j][k]+1.0*Dxx*((MMHg[i][j][k]-MMHg[i-1][j][k])/dx))/dx)-1.0*dt*(fluMMHgy[i][j][k]/dy)-1.0*dt*((fluMMHgz[i][j][k]+1.0*Dzz*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
         //  SPM[i][j][k]+= (SLSPM[i][j][k]+G1[i][j][k]*Wp1*b1[i][j][k])*pow(10.0,-12.0)*dt-1.0*dt*((fluSPMx[i][j][k]+1.0*Dxx*((SPM[i][j][k]-SPM[i-1][j][k])/dx))/dx)-1.0*dt*(fluSPMy[i][j][k]/dy)-1.0*dt*((fluSPMz[i][j][k]+1.0*Dzz*((SPM[i][j][k]-SPM[i][j][k-1])/dz))/dz); // Kg/l
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*((fluRx[i][j][k]+1.0*Dxx*((R[i][j][k]-R[i-1][j][k])/dx))/dx)-1.0*dt*(fluRy[i][j][k]/dy)-1.0*dt*((fluRz[i][j][k]+1.0*Dzz*((R[i][j][k]-R[i][j][k-1])/dz))/dz);
           } 
			
           }
           else if(Rini[i-1][j][k]<Rin && Rini[i][j-1][k]>=Rin && Rini[i][j][k-1]>=Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*(flub1x[i][j][k]/dx)-1.0*dt*((flub1y[i][j][k]+1.0*Dyy*((b1[i][j][k]-b1[i][j-1][k])/dy))/dy)-1.0*dt*((flub1z[i][j][k]+1.0*Dzz*((b1[i][j][k]-b1[i][j][k-1])/dz))/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3)*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*(fluHg0x[i][j][k]/dx)-1.0*dt*((fluHg0y[i][j][k]+1.0*Dyy*((Hg0[i][j][k]-Hg0[i][j-1][k])/dy))/dy)-1.0*dt*((fluHg0z[i][j][k]+1.0*Dzz*((Hg0[i][j][k]-Hg0[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3)*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*kmeth*HgII[i][j][k]*dt-1.0*dt*(fluHgIIx[i][j][k]/dx)-1.0*dt*((fluHgIIy[i][j][k]+1.0*Dyy*((HgII[i][j][k]-HgII[i][j-1][k])/dy))/dy)-1.0*dt*((fluHgIIz[i][j][k]+1.0*Dzz*((HgII[i][j][k]-HgII[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-1.0*dt*(fluMMHgx[i][j][k]/dx)-1.0*dt*((fluMMHgy[i][j][k]+1.0*Dyy*((MMHg[i][j][k]-MMHg[i][j-1][k])/dy))/dy)-1.0*dt*((fluMMHgz[i][j][k]+1.0*Dzz*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
         //  SPM[i][j][k]+= (SLSPM[i][j][k]+G1[i][j][k]*Wp1*b1[i][j][k])*pow(10.0,-12.0)*dt-1.0*dt*(fluSPMx[i][j][k]/dx)-1.0*dt*((fluSPMy[i][j][k]+1.0*Dyy*((SPM[i][j][k]-SPM[i][j-1][k])/dy))/dy)-1.0*dt*((fluSPMz[i][j][k]+1.0*Dzz*((SPM[i][j][k]-SPM[i][j][k-1])/dz))/dz); // Kg/l
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*(fluRx[i][j][k]/dx)-1.0*dt*((fluRy[i][j][k]+1.0*Dyy*((R[i][j][k]-R[i][j-1][k])/dy))/dy)-1.0*dt*((fluRz[i][j][k]+1.0*Dzz*((R[i][j][k]-R[i][j][k-1])/dz))/dz);
           } 
			
           } 
           else if(Rini[i-1][j][k]<Rin && Rini[i][j-1][k]<Rin && Rini[i][j][k-1]>=Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*(flub1x[i][j][k]/dx)-1.0*dt*(flub1y[i][j][k]/dy)-1.0*dt*((flub1z[i][j][k]+1.0*Dzz*((b1[i][j][k]-b1[i][j][k-1])/dz))/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3)*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*(fluHg0x[i][j][k]/dx)-1.0*dt*(fluHg0y[i][j][k]/dy)-1.0*dt*((fluHg0z[i][j][k]+1.0*Dzz*((Hg0[i][j][k]-Hg0[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3)*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*kmeth*HgII[i][j][k]*dt-1.0*dt*(fluHgIIx[i][j][k]/dx)-1.0*dt*(fluHgIIy[i][j][k]/dy)-1.0*dt*((fluHgIIz[i][j][k]+1.0*Dzz*((HgII[i][j][k]-HgII[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-1.0*dt*(fluMMHgx[i][j][k]/dx)-1.0*dt*(fluMMHgy[i][j][k]/dy)-1.0*dt*((fluMMHgz[i][j][k]+1.0*Dzz*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
         //  SPM[i][j][k]+= (SLSPM[i][j][k]+G1[i][j][k]*Wp1*b1[i][j][k])*pow(10.0,-12.0)*dt-1.0*dt*(fluSPMx[i][j][k]/dx)-1.0*dt*(fluSPMy[i][j][k]/dy)-1.0*dt*((fluSPMz[i][j][k]+1.0*Dzz*((SPM[i][j][k]-SPM[i][j][k-1])/dz))/dz); // Kg/l
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*(fluRx[i][j][k]/dx)-1.0*dt*(fluRy[i][j][k]/dy)-1.0*dt*((fluRz[i][j][k]+1.0*Dzz*((R[i][j][k]-R[i][j][k-1])/dz))/dz);
           } 
			
           } 
           else if(Rini[i-1][j][k]<Rin && Rini[i][j-1][k]>=Rin && Rini[i][j][k-1]<Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*(flub1x[i][j][k]/dx)-1.0*dt*((flub1y[i][j][k]+1.0*Dyy*((b1[i][j][k]-b1[i][j-1][k])/dy))/dy)-1.0*dt*(flub1z[i][j][k]/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3)*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*(fluHg0x[i][j][k]/dx)-1.0*dt*((fluHg0y[i][j][k]+1.0*Dyy*((Hg0[i][j][k]-Hg0[i][j-1][k])/dy))/dy)-1.0*dt*(fluHg0z[i][j][k]/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3)*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*kmeth*HgII[i][j][k]*dt-1.0*dt*(fluHgIIx[i][j][k]/dx)-1.0*dt*((fluHgIIy[i][j][k]+1.0*Dyy*((HgII[i][j][k]-HgII[i][j-1][k])/dy))/dy)-1.0*dt*(fluHgIIz[i][j][k]/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-1.0*dt*(fluMMHgx[i][j][k]/dx)-1.0*dt*((fluMMHgy[i][j][k]+1.0*Dyy*((MMHg[i][j][k]-MMHg[i][j-1][k])/dy))/dy)-1.0*dt*(fluMMHgz[i][j][k]/dz); // ng/l or microg/m^3
         //  SPM[i][j][k]+= (SLSPM[i][j][k]+G1[i][j][k]*Wp1*b1[i][j][k])*pow(10.0,-12.0)*dt-1.0*dt*(fluSPMx[i][j][k]/dx)-1.0*dt*((fluSPMy[i][j][k]+1.0*Dyy*((SPM[i][j][k]-SPM[i][j-1][k])/dy))/dy)-1.0*dt*(fluSPMz[i][j][k]/dz); // Kg/l
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*(fluRx[i][j][k]/dx)-1.0*dt*((fluRy[i][j][k]+1.0*Dyy*((R[i][j][k]-R[i][j-1][k])/dy))/dy)-1.0*dt*(fluRz[i][j][k]/dz);
           } 
			
           }  
           else if(Rini[i-1][j][k]>=Rin && Rini[i][j-1][k]<Rin && Rini[i][j][k-1]<Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*((flub1x[i][j][k]+1.0*Dxx*((b1[i][j][k]-b1[i-1][j][k])/dx))/dx)-1.0*dt*(flub1y[i][j][k]/dy)-1.0*dt*(flub1z[i][j][k]/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3)*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*((fluHg0x[i][j][k]+1.0*Dxx*((Hg0[i][j][k]-Hg0[i-1][j][k])/dx))/dx)-1.0*dt*(fluHg0y[i][j][k]/dy)-1.0*dt*(fluHg0z[i][j][k]/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3)*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*kmeth*HgII[i][j][k]*dt-1.0*dt*((fluHgIIx[i][j][k]+1.0*Dxx*((HgII[i][j][k]-HgII[i-1][j][k])/dx))/dx)-1.0*dt*(fluHgIIy[i][j][k]/dy)-1.0*dt*(fluHgIIz[i][j][k]/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-1.0*dt*((fluMMHgx[i][j][k]+1.0*Dxx*((MMHg[i][j][k]-MMHg[i-1][j][k])/dx))/dx)-1.0*dt*(fluMMHgy[i][j][k]/dy)-1.0*dt*(fluMMHgz[i][j][k]/dz); // ng/l or microg/m^3
         //  SPM[i][j][k]+= (SLSPM[i][j][k]+G1[i][j][k]*Wp1*b1[i][j][k])*pow(10.0,-12.0)*dt-1.0*dt*((fluSPMx[i][j][k]+1.0*Dxx*((SPM[i][j][k]-SPM[i-1][j][k])/dx))/dx)-1.0*dt*(fluSPMy[i][j][k]/dy)-1.0*dt*(fluSPMz[i][j][k]/dz); // Kg/l
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*((fluRx[i][j][k]+1.0*Dxx*((R[i][j][k]-R[i-1][j][k])/dx))/dx)-1.0*dt*(fluRy[i][j][k]/dy)-1.0*dt*(fluRz[i][j][k]/dz);
           } 
			
           }
           else{
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*(flub1x[i][j][k]/dx)-1.0*dt*(flub1y[i][j][k]/dy)-1.0*dt*(flub1z[i][j][k]/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3)*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*(fluHg0x[i][j][k]/dx)-1.0*dt*(fluHg0y[i][j][k]/dy)-1.0*dt*(fluHg0z[i][j][k]/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3)*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4)*HgII[i][j][k]*dt-1.0*kmeth*HgII[i][j][k]*dt-1.0*dt*(fluHgIIx[i][j][k]/dx)-1.0*dt*(fluHgIIy[i][j][k]/dy)-1.0*dt*(fluHgIIz[i][j][k]/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-1.0*dt*(fluMMHgx[i][j][k]/dx)-1.0*dt*(fluMMHgy[i][j][k]/dy)-1.0*dt*(fluMMHgz[i][j][k]/dz); // ng/l or microg/m^3
         //  SPM[i][j][k]+= (SLSPM[i][j][k]+G1[i][j][k]*Wp1*b1[i][j][k])*pow(10.0,-12.0)*dt-1.0*dt*(fluSPMx[i][j][k]/dx)-1.0*dt*(fluSPMy[i][j][k]/dy)-1.0*dt*(fluSPMz[i][j][k]/dz); // Kg/l
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*(fluRx[i][j][k]/dx)-1.0*dt*(fluRy[i][j][k]/dy)-1.0*dt*(fluRz[i][j][k]/dz);
           } 
			
           }
           
           
           if(b1[i][j][k]<=0.000000){
				b1[i][j][k]=0.0;
           }
  
           if(R[i][j][k]<=0.000000){
				R[i][j][k]=0.0;
           }
			
		   if(Hg0[i][j][k]<=0.000000){
				Hg0[i][j][k]=0.0;
		   }
			
		   if(HgII[i][j][k]<=0.000000){
				HgII[i][j][k]=0.0;
           }
			
		   if(MMHg[i][j][k]<=0.000000){
				MMHg[i][j][k]=0.0;
	       }
		/*	
		   if(SPM[i][j][k]<=0.000000){
				SPM[i][j][k]=0.0;
		   }
        */   
        }	
        else{
         
           b1[i][j][k]=0.0; // cell/m^3
           R[i][j][k]=0.0;
           Hg0[i][j][k]=0.0; // ng/l or microg/m^3
           HgII[i][j][k]=0.0; // ng/l or microg/m^3
           MMHg[i][j][k]=0.0; // ng/l or microg/m^3
                    
        }  
                 
        } 
     } 
  }        
                  
   for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
       for(k=1; k<=K; k++){ // rispetto allo spazio z
     
        if(Rini[i][j][k]>=Rin){
           
           DHg[i][j][k]=Hg0[i][j][k]+HgII[i][j][k]+MMHg[i][j][k];
           kphupII[i][j][k]=pow(Wp1,-kp)/(rowat+rolip*pow((HgII[i][j][k]*pow(10.0,-3.0)),blip)); // l/(Kg*d)
           kphupMM[i][j][k]=pow(Wp1,-kp)/(rowat+rolip*pow((MMHg[i][j][k]*pow(10.0,-3.0)),blip)); // l/(Kg*d)
           PHgII[i][j][k]+=(Wp1*kphupII[i][j][k]*HgII[i][j][k]*pow(10.0,-12.0))*(dt/24.0)-(kphexII+kphgr)*PHgII[i][j][k]*(dt/24.0); //  microg
           PMMHg[i][j][k]+=(Wp1*kphupMM[i][j][k]*MMHg[i][j][k]*pow(10.0,-12.0))*(dt/24.0)-(kphexMM+kphgr)*PMMHg[i][j][k]*(dt/24.0); //  microg
           PHg[i][j][k]=PHgII[i][j][k]+PMMHg[i][j][k]; //  microg
           THg[i][j][k]=Hg0[i][j][k]+HgII[i][j][k]*(1.0+kDSPM0*SPM[i][j][k])+MMHg[i][j][k]*(1.0+kDSPM0*SPM[i][j][k]);
           SIIDOM[i][j][k]=lambda1*m1*b1[i][j][k]*PHgII[i][j][k]; // microg/(m^3*h)
           SMMDOM[i][j][k]=lambda1*m1*b1[i][j][k]*PMMHg[i][j][k]; // microg/(m^3*h)
           SLSPM[i][j][k]=(m1*b1[i][j][k]*(1.0-lambda1)*Wp1); // microg/(m^3*h)
           chla1[i][j][k]=b1[i][j][k]*exp((((k-1)*dz)+33.72)/19.57)*pow(10.0,-12.0);  // mg/m^3
           chlatot[i][j][k]=chla1[i][j][k]+chla2;  // mg/m^3
           
           TotSIIDOM += SIIDOM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMHgII); // kmol
           TotSMMDOM += SMMDOM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMMMHg); // kmol
           
           if(DHg[i][j][k]<=0.000000){
				DHg[i][j][k]=0.0;
			}
           
           if(kphupII[i][j][k]<=0.000000){
				kphupII[i][j][k]=0.0;
			}
		   
		   if(kphupMM[i][j][k]<=0.000000){
				kphupMM[i][j][k]=0.0;
			}
		   
		   if(PHgII[i][j][k]<=0.000000){
				PHgII[i][j][k]=0.0;
			}
		   
		   if(PMMHg[i][j][k]<=0.000000){
				PMMHg[i][j][k]=0.0;
			}
			
           if(PHg[i][j][k]<=0.000000){
				PHg[i][j][k]=0.0;
			}
			
		   if(THg[i][j][k]<=0.000000){
				THg[i][j][k]=0.0;
			}
		   
		   if(SIIDOM[i][j][k]<=0.000000){
				SIIDOM[i][j][k]=0.0;
			}
		   
		   if(SMMDOM[i][j][k]<=0.000000){
				SMMDOM[i][j][k]=0.0;
			}
		   
		   if(SLSPM[i][j][k]<=0.000000){
				SLSPM[i][j][k]=0.0;
			}
		   
		   if(chla1[i][j][k]<=0.000000){
				chla1[i][j][k]=0.0;
			}
		   
           if(chlatot[i][j][k]<=0.000000){
				chlatot[i][j][k]=0.0;
			}
           
          // SPIM[i][j][k]=(1.0-forg[i][j][k])*SPM[i][j][k]; //  Kg/l
          // SPOM[i][j][k]=forg[i][j][k]*SPM[i][j][k]; //  Kg/l
           
           vz[i][j][k]=vz0; // m/h
           
           peratio=-0.0081*Tatm+0.0806*log(chlas)+0.426; //dimensionless
           OCRR=(NPP/(12.011*75.0))*(1.0-peratio); // mol/m^3 *h
           k3=k3bio*OCRR; // h
           k4=k4bio*OCRR; //h
            
           if(k==1){
               SIISPM[i][j][k]=NPP*peratio*(kD0/forg[i][j][k])*pow(10,-6.0)*(HgII[i][j][k]/(dz/2.0));
               SMMSPM[i][j][k]=NPP*peratio*(kD0/forg[i][j][k])*pow(10,-6.0)*(MMHg[i][j][k]/(dz/2.0));
           }
           else{
               SIISPM[i][j][k]=NPP*peratio*(kD0/forg[i][j][k])*pow(10,-6.0)*((HgII[i][j][k]-HgII[i][j][k-1])/dz); // microg/(m^3*h)
               SMMSPM[i][j][k]=NPP*peratio*(kD0/forg[i][j][k])*pow(10,-6.0)*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz); // microg/(m^3*h)
           }
           
           TotSIISPM += SIISPM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMHgII); // kmol
           TotSMMSPM += SMMSPM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMMMHg); // kmol
           
           if(k==1){
              sommab1[i][j]=chla1[i][j][k];
              sommab2[i][j]=chla2;
              It[i][j][k]=Iin;
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           else{
              sommab1[i][j] += chla1[i][j][k];
              sommab2[i][j] += chla2;
              It[i][j][k]=Iin*exp(-(abg*(k-1)+(a2*(2*sommab2[i][j]-2*chla2)/2.0)+(a1*(2*sommab1[i][j]-chla1[i][j][k]-chla1[i][j][1])/2.0))*dz);
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           
           if(It[i][j][k]<=0.000000){
				It[i][j][k]=0.0;
			}
            
           F1I[i][j][k]=(r1*It[i][j][k])/(KI1+It[i][j][k]);
           F1R[i][j][k]=(r1*R[i][j][k])/(KR1+R[i][j][k]);
  
           if(F1I[i][j][k]>F1R[i][j][k]){
              G1[i][j][k]=F1R[i][j][k]-m1;
           }
           else{
              G1[i][j][k]=F1I[i][j][k]-m1;
           }   
                        
        }	
        else{
         
           vz[i][j][k]=0.0;
           DHg[i][j][k]=0.0;
           kphupII[i][j][k]=0.0;
           kphupMM[i][j][k]=0.0;
           PHgII[i][j][k]=0.0; //  microg
           PMMHg[i][j][k]=0.0; //  microg
           PHg[i][j][k]=0.0; 
           THg[i][j][k]=0.0;
           //SPIM[i][j][k]=0.0; // in Kg/l
           //SPOM[i][j][k]=0.0; // in Kg/l
           chla1[i][j][k]=0.0; // mg/m^3
           chlatot[i][j][k]=0.0; // mg/m^3
           SIIDOM[i][j][k]=0.0; // microg/(m^3*h)
           SMMDOM[i][j][k]=0.0; // microg/(m^3*h)
           SLSPM[i][j][k]=0.0; // microg/(m^3*h)
           SIISPM[i][j][k]=0.0;
           SMMSPM[i][j][k]=0.0;
           
           if(k==1){
              It[i][j][k]=Iin;
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           else{
              It[i][j][k]=0.0;
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           
           F1I[i][j][k]=0.0;
           F1R[i][j][k]=0.0;
           G1[i][j][k]=0.0;
           
        }
           
        } 
     } 
  }  
  
  for(i=1; i<=I; i++){
     for(j=1; j<=J; j++){
     
     if(Rini[i][j][1]>=Rin){
     
     if(dz1+Totdep[i][j]>0.000000){
      
     if(THgsedold[i][j][1]>0.000000){
         HgIIpw[i][j][1]+= Kdeme*MMHgpw[i][j][1]*dt-Kme*HgIIpw[i][j][1]*dt+(Dinsed[i][j][1]*(((HgIIpw[i][j][2]-HgIIpw[i][j][1])/dz2)-((HgIIpw[i][j][1]-HgIIpw[i][j][1])/(dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][1]*(HgIIpw[i+1][j][1]-2.0*HgIIpw[i][j][1]+HgIIpw[i-1][j][1]))*(dt/pow(dx,2.0))+(Dinsed[i][j][1]*(HgIIpw[i][j+1][1]-2.0*HgIIpw[i][j][1]+HgIIpw[i][j-1][1]))*(dt/pow(dy,2.0))+((Dinsed[i][j][2]-Dinsed[i][j][1])*(HgIIpw[i][j][2]-HgIIpw[i][j][1]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][1]-Dinsed[i][j][1])*(HgIIpw[i+1][j][1]-HgIIpw[i][j][1]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][1]-Dinsed[i][j][1])*(HgIIpw[i][j+1][1]-HgIIpw[i][j][1]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][1]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][1]+= Kme*HgIIpw[i][j][1]*dt-Kdeme*MMHgpw[i][j][1]*dt+(Dorsed[i][j][1]*(((MMHgpw[i][j][2]-MMHgpw[i][j][1])/dz2)-((MMHgpw[i][j][1]-MMHgpw[i][j][1])/(dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][1]*(MMHgpw[i+1][j][1]-2.0*MMHgpw[i][j][1]+MMHgpw[i-1][j][1]))*(dt/pow(dx,2.0))+(Dorsed[i][j][1]*(MMHgpw[i][j+1][1]-2.0*MMHgpw[i][j][1]+MMHgpw[i][j-1][1]))*(dt/pow(dy,2.0))+((Dorsed[i][j][2]-Dorsed[i][j][1])*(MMHgpw[i][j][2]-MMHgpw[i][j][1]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][1]-Dorsed[i][j][1])*(MMHgpw[i+1][j][1]-MMHgpw[i][j][1]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][1]-Dorsed[i][j][1])*(MMHgpw[i][j+1][1]-MMHgpw[i][j][1]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][1]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][1]+= -1.0*alfa*THgsed[i][j][1]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][1]+= Kdeme*MMHgpw[i][j][1]*dt-Kme*HgIIpw[i][j][1]*dt+(Dinsed[i][j][1]*(((HgIIpw[i][j][2]-HgIIpw[i][j][1])/dz2)-((HgIIpw[i][j][1]-HgIIpw[i][j][1])/(dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][1]*(HgIIpw[i+1][j][1]-2.0*HgIIpw[i][j][1]+HgIIpw[i-1][j][1]))*(dt/pow(dx,2.0))+(Dinsed[i][j][1]*(HgIIpw[i][j+1][1]-2.0*HgIIpw[i][j][1]+HgIIpw[i][j-1][1]))*(dt/pow(dy,2.0))+((Dinsed[i][j][2]-Dinsed[i][j][1])*(HgIIpw[i][j][2]-HgIIpw[i][j][1]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][1]-Dinsed[i][j][1])*(HgIIpw[i+1][j][1]-HgIIpw[i][j][1]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][1]-Dinsed[i][j][1])*(HgIIpw[i][j+1][1]-HgIIpw[i][j][1]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][1]+= Kme*HgIIpw[i][j][1]*dt-Kdeme*MMHgpw[i][j][1]*dt+(Dorsed[i][j][1]*(((MMHgpw[i][j][2]-MMHgpw[i][j][1])/dz2)-((MMHgpw[i][j][1]-MMHgpw[i][j][1])/(dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][1]*(MMHgpw[i+1][j][1]-2.0*MMHgpw[i][j][1]+MMHgpw[i-1][j][1]))*(dt/pow(dx,2.0))+(Dorsed[i][j][1]*(MMHgpw[i][j+1][1]-2.0*MMHgpw[i][j][1]+MMHgpw[i][j-1][1]))*(dt/pow(dy,2.0))+((Dorsed[i][j][2]-Dorsed[i][j][1])*(MMHgpw[i][j][2]-MMHgpw[i][j][1]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][1]-Dorsed[i][j][1])*(MMHgpw[i+1][j][1]-MMHgpw[i][j][1]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][1]-Dorsed[i][j][1])*(MMHgpw[i][j+1][1]-MMHgpw[i][j][1]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][1]+= 0.0; // mg/Kg
     }

     
     for(r=2; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }

     }
     else if(dz1+Totdep[i][j]<=0.000000 && dz1+dz2+Totdep[i][j]>0.000000){
     
     if(THgsedold[i][j][2]>0.000000){
         HgIIpw[i][j][2]+= Kdeme*MMHgpw[i][j][2]*dt-Kme*HgIIpw[i][j][2]*dt+(Dinsed[i][j][2]*(((HgIIpw[i][j][3]-HgIIpw[i][j][2])/dz2)-((HgIIpw[i][j][2]-HgIIpw[i][j][2])/(dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][2]*(HgIIpw[i+1][j][2]-2.0*HgIIpw[i][j][2]+HgIIpw[i-1][j][2]))*(dt/pow(dx,2.0))+(Dinsed[i][j][2]*(HgIIpw[i][j+1][2]-2.0*HgIIpw[i][j][2]+HgIIpw[i][j-1][2]))*(dt/pow(dy,2.0))+((Dinsed[i][j][3]-Dinsed[i][j][2])*(HgIIpw[i][j][3]-HgIIpw[i][j][2]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][2]-Dinsed[i][j][2])*(HgIIpw[i+1][j][2]-HgIIpw[i][j][2]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][2]-Dinsed[i][j][2])*(HgIIpw[i][j+1][2]-HgIIpw[i][j][2]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][2]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][2]+= Kme*HgIIpw[i][j][2]*dt-Kdeme*MMHgpw[i][j][2]*dt+(Dorsed[i][j][2]*(((MMHgpw[i][j][3]-MMHgpw[i][j][2])/dz2)-((MMHgpw[i][j][2]-MMHgpw[i][j][2])/(dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][2]*(MMHgpw[i+1][j][2]-2.0*MMHgpw[i][j][2]+MMHgpw[i-1][j][2]))*(dt/pow(dx,2.0))+(Dorsed[i][j][2]*(MMHgpw[i][j+1][2]-2.0*MMHgpw[i][j][2]+MMHgpw[i][j-1][2]))*(dt/pow(dy,2.0))+((Dorsed[i][j][3]-Dorsed[i][j][2])*(MMHgpw[i][j][3]-MMHgpw[i][j][2]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][2]-Dorsed[i][j][2])*(MMHgpw[i+1][j][2]-MMHgpw[i][j][2]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][2]-Dorsed[i][j][2])*(MMHgpw[i][j+1][2]-MMHgpw[i][j][2]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][2]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][2]+= -1.0*alfa*THgsed[i][j][2]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][2]+= Kdeme*MMHgpw[i][j][2]*dt-Kme*HgIIpw[i][j][2]*dt+(Dinsed[i][j][2]*(((HgIIpw[i][j][3]-HgIIpw[i][j][2])/dz2)-((HgIIpw[i][j][2]-HgIIpw[i][j][2])/(dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][2]*(HgIIpw[i+1][j][2]-2.0*HgIIpw[i][j][2]+HgIIpw[i-1][j][2]))*(dt/pow(dx,2.0))+(Dinsed[i][j][2]*(HgIIpw[i][j+1][2]-2.0*HgIIpw[i][j][2]+HgIIpw[i][j-1][2]))*(dt/pow(dy,2.0))+((Dinsed[i][j][3]-Dinsed[i][j][2])*(HgIIpw[i][j][3]-HgIIpw[i][j][2]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][2]-Dinsed[i][j][2])*(HgIIpw[i+1][j][2]-HgIIpw[i][j][2]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][2]-Dinsed[i][j][2])*(HgIIpw[i][j+1][2]-HgIIpw[i][j][2]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][2]+= Kme*HgIIpw[i][j][2]*dt-Kdeme*MMHgpw[i][j][2]*dt+(Dorsed[i][j][2]*(((MMHgpw[i][j][3]-MMHgpw[i][j][2])/dz2)-((MMHgpw[i][j][2]-MMHgpw[i][j][2])/(dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][2]*(MMHgpw[i+1][j][2]-2.0*MMHgpw[i][j][2]+MMHgpw[i-1][j][2]))*(dt/pow(dx,2.0))+(Dorsed[i][j][2]*(MMHgpw[i][j+1][2]-2.0*MMHgpw[i][j][2]+MMHgpw[i][j-1][2]))*(dt/pow(dy,2.0))+((Dorsed[i][j][3]-Dorsed[i][j][2])*(MMHgpw[i][j][3]-MMHgpw[i][j][2]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][2]-Dorsed[i][j][2])*(MMHgpw[i+1][j][2]-MMHgpw[i][j][2]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][2]-Dorsed[i][j][2])*(MMHgpw[i][j+1][2]-MMHgpw[i][j][2]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][2]+= 0.0; // mg/Kg
     }

     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];
     
     for(r=3; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }
     
     
     }
     else if(dz1+dz2+Totdep[i][j]<=0.000000 && dz1+2.0*dz2+Totdep[i][j]>0.000000){

     if(THgsedold[i][j][3]>0.000000){
         HgIIpw[i][j][3]+= Kdeme*MMHgpw[i][j][3]*dt-Kme*HgIIpw[i][j][3]*dt+(Dinsed[i][j][3]*(((HgIIpw[i][j][4]-HgIIpw[i][j][3])/dz2)-((HgIIpw[i][j][3]-HgIIpw[i][j][3])/(2.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][3]*(HgIIpw[i+1][j][3]-2.0*HgIIpw[i][j][3]+HgIIpw[i-1][j][3]))*(dt/pow(dx,2.0))+(Dinsed[i][j][3]*(HgIIpw[i][j+1][3]-2.0*HgIIpw[i][j][3]+HgIIpw[i][j-1][3]))*(dt/pow(dy,2.0))+((Dinsed[i][j][4]-Dinsed[i][j][3])*(HgIIpw[i][j][4]-HgIIpw[i][j][3]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][3]-Dinsed[i][j][3])*(HgIIpw[i+1][j][3]-HgIIpw[i][j][3]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][3]-Dinsed[i][j][3])*(HgIIpw[i][j+1][3]-HgIIpw[i][j][3]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][3]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][3]+= Kme*HgIIpw[i][j][3]*dt-Kdeme*MMHgpw[i][j][3]*dt+(Dorsed[i][j][3]*(((MMHgpw[i][j][4]-MMHgpw[i][j][3])/dz2)-((MMHgpw[i][j][3]-MMHgpw[i][j][3])/(2.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][3]*(MMHgpw[i+1][j][3]-2.0*MMHgpw[i][j][3]+MMHgpw[i-1][j][3]))*(dt/pow(dx,2.0))+(Dorsed[i][j][3]*(MMHgpw[i][j+1][3]-2.0*MMHgpw[i][j][3]+MMHgpw[i][j-1][3]))*(dt/pow(dy,2.0))+((Dorsed[i][j][4]-Dorsed[i][j][3])*(MMHgpw[i][j][4]-MMHgpw[i][j][3]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][3]-Dorsed[i][j][3])*(MMHgpw[i+1][j][3]-MMHgpw[i][j][3]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][3]-Dorsed[i][j][3])*(MMHgpw[i][j+1][3]-MMHgpw[i][j][3]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][3]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][3]+= -1.0*alfa*THgsed[i][j][3]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][3]+= Kdeme*MMHgpw[i][j][3]*dt-Kme*HgIIpw[i][j][3]*dt+(Dinsed[i][j][3]*(((HgIIpw[i][j][4]-HgIIpw[i][j][3])/dz2)-((HgIIpw[i][j][3]-HgIIpw[i][j][3])/(2.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][3]*(HgIIpw[i+1][j][3]-2.0*HgIIpw[i][j][3]+HgIIpw[i-1][j][3]))*(dt/pow(dx,2.0))+(Dinsed[i][j][3]*(HgIIpw[i][j+1][3]-2.0*HgIIpw[i][j][3]+HgIIpw[i][j-1][3]))*(dt/pow(dy,2.0))+((Dinsed[i][j][4]-Dinsed[i][j][3])*(HgIIpw[i][j][4]-HgIIpw[i][j][3]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][3]-Dinsed[i][j][3])*(HgIIpw[i+1][j][3]-HgIIpw[i][j][3]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][3]-Dinsed[i][j][3])*(HgIIpw[i][j+1][3]-HgIIpw[i][j][3]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][3]+= Kme*HgIIpw[i][j][3]*dt-Kdeme*MMHgpw[i][j][3]*dt+(Dorsed[i][j][3]*(((MMHgpw[i][j][4]-MMHgpw[i][j][3])/dz2)-((MMHgpw[i][j][3]-MMHgpw[i][j][3])/(2.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][3]*(MMHgpw[i+1][j][3]-2.0*MMHgpw[i][j][3]+MMHgpw[i-1][j][3]))*(dt/pow(dx,2.0))+(Dorsed[i][j][3]*(MMHgpw[i][j+1][3]-2.0*MMHgpw[i][j][3]+MMHgpw[i][j-1][3]))*(dt/pow(dy,2.0))+((Dorsed[i][j][4]-Dorsed[i][j][3])*(MMHgpw[i][j][4]-MMHgpw[i][j][3]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][3]-Dorsed[i][j][3])*(MMHgpw[i+1][j][3]-MMHgpw[i][j][3]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][3]-Dorsed[i][j][3])*(MMHgpw[i][j+1][3]-MMHgpw[i][j][3]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][3]+= 0.0; // mg/Kg
     }
     
     HgIIpw[i][j][2]=HgIIpw[i][j][3];
     MMHgpw[i][j][2]=MMHgpw[i][j][3];
     THgsed[i][j][2]=THgsed[i][j][3];
     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];
     
     for(r=4; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }
     
     }
     else if(dz1+2.0*dz2+Totdep[i][j]<=0.000000 && dz1+3.0*dz2+Totdep[i][j]>0.000000){

     if(THgsedold[i][j][4]>0.000000){
         HgIIpw[i][j][4]+= Kdeme*MMHgpw[i][j][4]*dt-Kme*HgIIpw[i][j][4]*dt+(Dinsed[i][j][4]*(((HgIIpw[i][j][5]-HgIIpw[i][j][4])/dz2)-((HgIIpw[i][j][4]-HgIIpw[i][j][4])/(3.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][4]*(HgIIpw[i+1][j][4]-2.0*HgIIpw[i][j][4]+HgIIpw[i-1][j][4]))*(dt/pow(dx,2.0))+(Dinsed[i][j][4]*(HgIIpw[i][j+1][4]-2.0*HgIIpw[i][j][4]+HgIIpw[i][j-1][4]))*(dt/pow(dy,2.0))+((Dinsed[i][j][5]-Dinsed[i][j][4])*(HgIIpw[i][j][5]-HgIIpw[i][j][4]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][4]-Dinsed[i][j][4])*(HgIIpw[i+1][j][4]-HgIIpw[i][j][4]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][4]-Dinsed[i][j][4])*(HgIIpw[i][j+1][4]-HgIIpw[i][j][4]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][4]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][4]+= Kme*HgIIpw[i][j][4]*dt-Kdeme*MMHgpw[i][j][4]*dt+(Dorsed[i][j][4]*(((MMHgpw[i][j][5]-MMHgpw[i][j][4])/dz2)-((MMHgpw[i][j][4]-MMHgpw[i][j][4])/(3.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][4]*(MMHgpw[i+1][j][4]-2.0*MMHgpw[i][j][4]+MMHgpw[i-1][j][4]))*(dt/pow(dx,2.0))+(Dorsed[i][j][4]*(MMHgpw[i][j+1][4]-2.0*MMHgpw[i][j][4]+MMHgpw[i][j-1][4]))*(dt/pow(dy,2.0))+((Dorsed[i][j][5]-Dorsed[i][j][4])*(MMHgpw[i][j][5]-MMHgpw[i][j][4]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][4]-Dorsed[i][j][4])*(MMHgpw[i+1][j][4]-MMHgpw[i][j][4]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][4]-Dorsed[i][j][4])*(MMHgpw[i][j+1][4]-MMHgpw[i][j][4]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][4]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][4]+= -1.0*alfa*THgsed[i][j][4]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][4]+= Kdeme*MMHgpw[i][j][4]*dt-Kme*HgIIpw[i][j][4]*dt+(Dinsed[i][j][4]*(((HgIIpw[i][j][5]-HgIIpw[i][j][4])/dz2)-((HgIIpw[i][j][4]-HgIIpw[i][j][4])/(3.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][4]*(HgIIpw[i+1][j][4]-2.0*HgIIpw[i][j][4]+HgIIpw[i-1][j][4]))*(dt/pow(dx,2.0))+(Dinsed[i][j][4]*(HgIIpw[i][j+1][4]-2.0*HgIIpw[i][j][4]+HgIIpw[i][j-1][4]))*(dt/pow(dy,2.0))+((Dinsed[i][j][5]-Dinsed[i][j][4])*(HgIIpw[i][j][5]-HgIIpw[i][j][4]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][4]-Dinsed[i][j][4])*(HgIIpw[i+1][j][4]-HgIIpw[i][j][4]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][4]-Dinsed[i][j][4])*(HgIIpw[i][j+1][4]-HgIIpw[i][j][4]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][4]+= Kme*HgIIpw[i][j][4]*dt-Kdeme*MMHgpw[i][j][4]*dt+(Dorsed[i][j][4]*(((MMHgpw[i][j][5]-MMHgpw[i][j][4])/dz2)-((MMHgpw[i][j][4]-MMHgpw[i][j][4])/(3.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][4]*(MMHgpw[i+1][j][4]-2.0*MMHgpw[i][j][4]+MMHgpw[i-1][j][4]))*(dt/pow(dx,2.0))+(Dorsed[i][j][4]*(MMHgpw[i][j+1][4]-2.0*MMHgpw[i][j][4]+MMHgpw[i][j-1][4]))*(dt/pow(dy,2.0))+((Dorsed[i][j][5]-Dorsed[i][j][4])*(MMHgpw[i][j][5]-MMHgpw[i][j][4]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][4]-Dorsed[i][j][4])*(MMHgpw[i+1][j][4]-MMHgpw[i][j][4]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][4]-Dorsed[i][j][4])*(MMHgpw[i][j+1][4]-MMHgpw[i][j][4]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][4]+= 0.0; // mg/Kg
     }
     
     HgIIpw[i][j][3]=HgIIpw[i][j][4];
     MMHgpw[i][j][3]=MMHgpw[i][j][4];
     THgsed[i][j][3]=THgsed[i][j][4];
     HgIIpw[i][j][2]=HgIIpw[i][j][3];
     MMHgpw[i][j][2]=MMHgpw[i][j][3];
     THgsed[i][j][2]=THgsed[i][j][3];
     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];
     
     
     for(r=5; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }
     
     }
     else if(dz1+3.0*dz2+Totdep[i][j]<=0.000000 && dz1+4.0*dz2+Totdep[i][j]>0.000000){

     if(THgsedold[i][j][5]>0.000000){
         HgIIpw[i][j][5]+= Kdeme*MMHgpw[i][j][5]*dt-Kme*HgIIpw[i][j][5]*dt+(Dinsed[i][j][5]*(((HgIIpw[i][j][6]-HgIIpw[i][j][5])/dz2)-((HgIIpw[i][j][5]-HgIIpw[i][j][5])/(4.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][5]*(HgIIpw[i+1][j][5]-2.0*HgIIpw[i][j][5]+HgIIpw[i-1][j][5]))*(dt/pow(dx,2.0))+(Dinsed[i][j][5]*(HgIIpw[i][j+1][5]-2.0*HgIIpw[i][j][5]+HgIIpw[i][j-1][5]))*(dt/pow(dy,2.0))+((Dinsed[i][j][6]-Dinsed[i][j][5])*(HgIIpw[i][j][6]-HgIIpw[i][j][5]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][5]-Dinsed[i][j][5])*(HgIIpw[i+1][j][5]-HgIIpw[i][j][5]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][5]-Dinsed[i][j][5])*(HgIIpw[i][j+1][5]-HgIIpw[i][j][5]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][5]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][5]+= Kme*HgIIpw[i][j][5]*dt-Kdeme*MMHgpw[i][j][5]*dt+(Dorsed[i][j][5]*(((MMHgpw[i][j][6]-MMHgpw[i][j][5])/dz2)-((MMHgpw[i][j][5]-MMHgpw[i][j][5])/(4.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][5]*(MMHgpw[i+1][j][5]-2.0*MMHgpw[i][j][5]+MMHgpw[i-1][j][5]))*(dt/pow(dx,2.0))+(Dorsed[i][j][5]*(MMHgpw[i][j+1][5]-2.0*MMHgpw[i][j][5]+MMHgpw[i][j-1][5]))*(dt/pow(dy,2.0))+((Dorsed[i][j][6]-Dorsed[i][j][5])*(MMHgpw[i][j][6]-MMHgpw[i][j][5]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][5]-Dorsed[i][j][5])*(MMHgpw[i+1][j][5]-MMHgpw[i][j][5]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][5]-Dorsed[i][j][5])*(MMHgpw[i][j+1][5]-MMHgpw[i][j][5]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][5]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][5]+= -1.0*alfa*THgsed[i][j][5]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][5]+= Kdeme*MMHgpw[i][j][5]*dt-Kme*HgIIpw[i][j][5]*dt+(Dinsed[i][j][5]*(((HgIIpw[i][j][6]-HgIIpw[i][j][5])/dz2)-((HgIIpw[i][j][5]-HgIIpw[i][j][5])/(4.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][5]*(HgIIpw[i+1][j][5]-2.0*HgIIpw[i][j][5]+HgIIpw[i-1][j][5]))*(dt/pow(dx,2.0))+(Dinsed[i][j][5]*(HgIIpw[i][j+1][5]-2.0*HgIIpw[i][j][5]+HgIIpw[i][j-1][5]))*(dt/pow(dy,2.0))+((Dinsed[i][j][6]-Dinsed[i][j][5])*(HgIIpw[i][j][6]-HgIIpw[i][j][5]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][5]-Dinsed[i][j][5])*(HgIIpw[i+1][j][5]-HgIIpw[i][j][5]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][5]-Dinsed[i][j][5])*(HgIIpw[i][j+1][5]-HgIIpw[i][j][5]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][5]+= Kme*HgIIpw[i][j][5]*dt-Kdeme*MMHgpw[i][j][5]*dt+(Dorsed[i][j][5]*(((MMHgpw[i][j][6]-MMHgpw[i][j][5])/dz2)-((MMHgpw[i][j][5]-MMHgpw[i][j][5])/(4.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][5]*(MMHgpw[i+1][j][5]-2.0*MMHgpw[i][j][5]+MMHgpw[i-1][j][5]))*(dt/pow(dx,2.0))+(Dorsed[i][j][5]*(MMHgpw[i][j+1][5]-2.0*MMHgpw[i][j][5]+MMHgpw[i][j-1][5]))*(dt/pow(dy,2.0))+((Dorsed[i][j][6]-Dorsed[i][j][5])*(MMHgpw[i][j][6]-MMHgpw[i][j][5]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][5]-Dorsed[i][j][5])*(MMHgpw[i+1][j][5]-MMHgpw[i][j][5]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][5]-Dorsed[i][j][5])*(MMHgpw[i][j+1][5]-MMHgpw[i][j][5]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][5]+= 0.0; // mg/Kg
     }
     
     HgIIpw[i][j][4]=HgIIpw[i][j][5];
     MMHgpw[i][j][4]=MMHgpw[i][j][5];
     THgsed[i][j][4]=THgsed[i][j][5];
     HgIIpw[i][j][3]=HgIIpw[i][j][4];
     MMHgpw[i][j][3]=MMHgpw[i][j][4];
     THgsed[i][j][3]=THgsed[i][j][4];
     HgIIpw[i][j][2]=HgIIpw[i][j][3];
     MMHgpw[i][j][2]=MMHgpw[i][j][3];
     THgsed[i][j][2]=THgsed[i][j][3];
     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];
     
     
     for(r=6; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }
     
     }
     else if(dz1+4.0*dz2+Totdep[i][j]<=0.000000 && dz1+5.0*dz2+Totdep[i][j]>0.000000){

     if(THgsedold[i][j][6]>0.000000){
         HgIIpw[i][j][6]+= Kdeme*MMHgpw[i][j][6]*dt-Kme*HgIIpw[i][j][6]*dt+(Dinsed[i][j][6]*(((HgIIpw[i][j][7]-HgIIpw[i][j][6])/dz2)-((HgIIpw[i][j][6]-HgIIpw[i][j][6])/(5.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][6]*(HgIIpw[i+1][j][6]-2.0*HgIIpw[i][j][6]+HgIIpw[i-1][j][6]))*(dt/pow(dx,2.0))+(Dinsed[i][j][6]*(HgIIpw[i][j+1][6]-2.0*HgIIpw[i][j][6]+HgIIpw[i][j-1][6]))*(dt/pow(dy,2.0))+((Dinsed[i][j][7]-Dinsed[i][j][6])*(HgIIpw[i][j][7]-HgIIpw[i][j][6]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][6]-Dinsed[i][j][6])*(HgIIpw[i+1][j][6]-HgIIpw[i][j][6]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][6]-Dinsed[i][j][6])*(HgIIpw[i][j+1][6]-HgIIpw[i][j][6]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][6]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][6]+= Kme*HgIIpw[i][j][6]*dt-Kdeme*MMHgpw[i][j][6]*dt+(Dorsed[i][j][6]*(((MMHgpw[i][j][7]-MMHgpw[i][j][6])/dz2)-((MMHgpw[i][j][6]-MMHgpw[i][j][6])/(5.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][6]*(MMHgpw[i+1][j][6]-2.0*MMHgpw[i][j][6]+MMHgpw[i-1][j][6]))*(dt/pow(dx,2.0))+(Dorsed[i][j][6]*(MMHgpw[i][j+1][6]-2.0*MMHgpw[i][j][6]+MMHgpw[i][j-1][6]))*(dt/pow(dy,2.0))+((Dorsed[i][j][7]-Dorsed[i][j][6])*(MMHgpw[i][j][7]-MMHgpw[i][j][6]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][6]-Dorsed[i][j][6])*(MMHgpw[i+1][j][6]-MMHgpw[i][j][6]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][6]-Dorsed[i][j][6])*(MMHgpw[i][j+1][6]-MMHgpw[i][j][6]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][6]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][6]+= -1.0*alfa*THgsed[i][j][6]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][6]+= Kdeme*MMHgpw[i][j][6]*dt-Kme*HgIIpw[i][j][6]*dt+(Dinsed[i][j][6]*(((HgIIpw[i][j][7]-HgIIpw[i][j][6])/dz2)-((HgIIpw[i][j][6]-HgIIpw[i][j][6])/(5.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][6]*(HgIIpw[i+1][j][6]-2.0*HgIIpw[i][j][6]+HgIIpw[i-1][j][6]))*(dt/pow(dx,2.0))+(Dinsed[i][j][6]*(HgIIpw[i][j+1][6]-2.0*HgIIpw[i][j][6]+HgIIpw[i][j-1][6]))*(dt/pow(dy,2.0))+((Dinsed[i][j][7]-Dinsed[i][j][6])*(HgIIpw[i][j][7]-HgIIpw[i][j][6]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][6]-Dinsed[i][j][6])*(HgIIpw[i+1][j][6]-HgIIpw[i][j][6]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][6]-Dinsed[i][j][6])*(HgIIpw[i][j+1][6]-HgIIpw[i][j][6]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][6]+= Kme*HgIIpw[i][j][6]*dt-Kdeme*MMHgpw[i][j][6]*dt+(Dorsed[i][j][6]*(((MMHgpw[i][j][7]-MMHgpw[i][j][6])/dz2)-((MMHgpw[i][j][6]-MMHgpw[i][j][6])/(5.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][6]*(MMHgpw[i+1][j][6]-2.0*MMHgpw[i][j][6]+MMHgpw[i-1][j][6]))*(dt/pow(dx,2.0))+(Dorsed[i][j][6]*(MMHgpw[i][j+1][6]-2.0*MMHgpw[i][j][6]+MMHgpw[i][j-1][6]))*(dt/pow(dy,2.0))+((Dorsed[i][j][7]-Dorsed[i][j][6])*(MMHgpw[i][j][7]-MMHgpw[i][j][6]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][6]-Dorsed[i][j][6])*(MMHgpw[i+1][j][6]-MMHgpw[i][j][6]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][6]-Dorsed[i][j][6])*(MMHgpw[i][j+1][6]-MMHgpw[i][j][6]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][6]+= 0.0; // mg/Kg
     }
     
     HgIIpw[i][j][5]=HgIIpw[i][j][6];
     MMHgpw[i][j][5]=MMHgpw[i][j][6];
     THgsed[i][j][5]=THgsed[i][j][6];
     HgIIpw[i][j][4]=HgIIpw[i][j][5];
     MMHgpw[i][j][4]=MMHgpw[i][j][5];
     THgsed[i][j][4]=THgsed[i][j][5];
     HgIIpw[i][j][3]=HgIIpw[i][j][4];
     MMHgpw[i][j][3]=MMHgpw[i][j][4];
     THgsed[i][j][3]=THgsed[i][j][4];
     HgIIpw[i][j][2]=HgIIpw[i][j][3];
     MMHgpw[i][j][2]=MMHgpw[i][j][3];
     THgsed[i][j][2]=THgsed[i][j][3];
     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];
     
     
     for(r=7; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }

     }
     else if(dz1+5.0*dz2+Totdep[i][j]<=0.000000 && dz1+6.0*dz2+Totdep[i][j]>0.000000){

     if(THgsedold[i][j][7]>0.000000){
         HgIIpw[i][j][7]+= Kdeme*MMHgpw[i][j][7]*dt-Kme*HgIIpw[i][j][7]*dt+(Dinsed[i][j][7]*(((HgIIpw[i][j][8]-HgIIpw[i][j][7])/dz2)-((HgIIpw[i][j][7]-HgIIpw[i][j][7])/(6.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][7]*(HgIIpw[i+1][j][7]-2.0*HgIIpw[i][j][7]+HgIIpw[i-1][j][7]))*(dt/pow(dx,2.0))+(Dinsed[i][j][7]*(HgIIpw[i][j+1][7]-2.0*HgIIpw[i][j][7]+HgIIpw[i][j-1][7]))*(dt/pow(dy,2.0))+((Dinsed[i][j][8]-Dinsed[i][j][7])*(HgIIpw[i][j][8]-HgIIpw[i][j][7]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][7]-Dinsed[i][j][7])*(HgIIpw[i+1][j][7]-HgIIpw[i][j][7]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][7]-Dinsed[i][j][7])*(HgIIpw[i][j+1][7]-HgIIpw[i][j][7]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][7]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][7]+= Kme*HgIIpw[i][j][7]*dt-Kdeme*MMHgpw[i][j][7]*dt+(Dorsed[i][j][7]*(((MMHgpw[i][j][8]-MMHgpw[i][j][7])/dz2)-((MMHgpw[i][j][7]-MMHgpw[i][j][7])/(6.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][7]*(MMHgpw[i+1][j][7]-2.0*MMHgpw[i][j][7]+MMHgpw[i-1][j][7]))*(dt/pow(dx,2.0))+(Dorsed[i][j][7]*(MMHgpw[i][j+1][7]-2.0*MMHgpw[i][j][7]+MMHgpw[i][j-1][7]))*(dt/pow(dy,2.0))+((Dorsed[i][j][8]-Dorsed[i][j][7])*(MMHgpw[i][j][8]-MMHgpw[i][j][7]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][7]-Dorsed[i][j][7])*(MMHgpw[i+1][j][7]-MMHgpw[i][j][7]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][7]-Dorsed[i][j][7])*(MMHgpw[i][j+1][7]-MMHgpw[i][j][7]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][7]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][7]+= -1.0*alfa*THgsed[i][j][7]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][7]+= Kdeme*MMHgpw[i][j][7]*dt-Kme*HgIIpw[i][j][7]*dt+(Dinsed[i][j][7]*(((HgIIpw[i][j][8]-HgIIpw[i][j][7])/dz2)-((HgIIpw[i][j][7]-HgIIpw[i][j][7])/(6.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][7]*(HgIIpw[i+1][j][7]-2.0*HgIIpw[i][j][7]+HgIIpw[i-1][j][7]))*(dt/pow(dx,2.0))+(Dinsed[i][j][7]*(HgIIpw[i][j+1][7]-2.0*HgIIpw[i][j][7]+HgIIpw[i][j-1][7]))*(dt/pow(dy,2.0))+((Dinsed[i][j][8]-Dinsed[i][j][7])*(HgIIpw[i][j][8]-HgIIpw[i][j][7]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][7]-Dinsed[i][j][7])*(HgIIpw[i+1][j][7]-HgIIpw[i][j][7]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][7]-Dinsed[i][j][7])*(HgIIpw[i][j+1][7]-HgIIpw[i][j][7]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][7]+= Kme*HgIIpw[i][j][7]*dt-Kdeme*MMHgpw[i][j][7]*dt+(Dorsed[i][j][7]*(((MMHgpw[i][j][8]-MMHgpw[i][j][7])/dz2)-((MMHgpw[i][j][7]-MMHgpw[i][j][7])/(6.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][7]*(MMHgpw[i+1][j][7]-2.0*MMHgpw[i][j][7]+MMHgpw[i-1][j][7]))*(dt/pow(dx,2.0))+(Dorsed[i][j][7]*(MMHgpw[i][j+1][7]-2.0*MMHgpw[i][j][7]+MMHgpw[i][j-1][7]))*(dt/pow(dy,2.0))+((Dorsed[i][j][8]-Dorsed[i][j][7])*(MMHgpw[i][j][8]-MMHgpw[i][j][7]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][7]-Dorsed[i][j][7])*(MMHgpw[i+1][j][7]-MMHgpw[i][j][7]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][7]-Dorsed[i][j][7])*(MMHgpw[i][j+1][7]-MMHgpw[i][j][7]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][7]+= 0.0; // mg/Kg
     }
     
     HgIIpw[i][j][6]=HgIIpw[i][j][7];
     MMHgpw[i][j][6]=MMHgpw[i][j][7];
     THgsed[i][j][6]=THgsed[i][j][7];
     HgIIpw[i][j][5]=HgIIpw[i][j][6];
     MMHgpw[i][j][5]=MMHgpw[i][j][6];
     THgsed[i][j][5]=THgsed[i][j][6];
     HgIIpw[i][j][4]=HgIIpw[i][j][5];
     MMHgpw[i][j][4]=MMHgpw[i][j][5];
     THgsed[i][j][4]=THgsed[i][j][5];
     HgIIpw[i][j][3]=HgIIpw[i][j][4];
     MMHgpw[i][j][3]=MMHgpw[i][j][4];
     THgsed[i][j][3]=THgsed[i][j][4];
     HgIIpw[i][j][2]=HgIIpw[i][j][3];
     MMHgpw[i][j][2]=MMHgpw[i][j][3];
     THgsed[i][j][2]=THgsed[i][j][3];
     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];
     
     
     for(r=8; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }
  
     }
     else if(dz1+6.0*dz2+Totdep[i][j]<=0.000000 && dz1+7.0*dz2+Totdep[i][j]>0.000000){

     if(THgsedold[i][j][8]>0.000000){
         HgIIpw[i][j][8]+= Kdeme*MMHgpw[i][j][8]*dt-Kme*HgIIpw[i][j][8]*dt+(Dinsed[i][j][8]*(((HgIIpw[i][j][9]-HgIIpw[i][j][8])/dz2)-((HgIIpw[i][j][8]-HgIIpw[i][j][8])/(7.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][8]*(HgIIpw[i+1][j][8]-2.0*HgIIpw[i][j][8]+HgIIpw[i-1][j][8]))*(dt/pow(dx,2.0))+(Dinsed[i][j][8]*(HgIIpw[i][j+1][8]-2.0*HgIIpw[i][j][8]+HgIIpw[i][j-1][8]))*(dt/pow(dy,2.0))+((Dinsed[i][j][9]-Dinsed[i][j][8])*(HgIIpw[i][j][9]-HgIIpw[i][j][8]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][8]-Dinsed[i][j][8])*(HgIIpw[i+1][j][8]-HgIIpw[i][j][8]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][8]-Dinsed[i][j][8])*(HgIIpw[i][j+1][8]-HgIIpw[i][j][8]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][8]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][8]+= Kme*HgIIpw[i][j][8]*dt-Kdeme*MMHgpw[i][j][8]*dt+(Dorsed[i][j][8]*(((MMHgpw[i][j][9]-MMHgpw[i][j][8])/dz2)-((MMHgpw[i][j][8]-MMHgpw[i][j][8])/(7.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][8]*(MMHgpw[i+1][j][8]-2.0*MMHgpw[i][j][8]+MMHgpw[i-1][j][8]))*(dt/pow(dx,2.0))+(Dorsed[i][j][8]*(MMHgpw[i][j+1][8]-2.0*MMHgpw[i][j][8]+MMHgpw[i][j-1][8]))*(dt/pow(dy,2.0))+((Dorsed[i][j][9]-Dorsed[i][j][8])*(MMHgpw[i][j][9]-MMHgpw[i][j][8]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][8]-Dorsed[i][j][8])*(MMHgpw[i+1][j][8]-MMHgpw[i][j][8]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][8]-Dorsed[i][j][8])*(MMHgpw[i][j+1][8]-MMHgpw[i][j][8]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][8]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][8]+= -1.0*alfa*THgsed[i][j][8]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][8]+= Kdeme*MMHgpw[i][j][8]*dt-Kme*HgIIpw[i][j][8]*dt+(Dinsed[i][j][8]*(((HgIIpw[i][j][9]-HgIIpw[i][j][8])/dz2)-((HgIIpw[i][j][8]-HgIIpw[i][j][8])/(7.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][8]*(HgIIpw[i+1][j][8]-2.0*HgIIpw[i][j][8]+HgIIpw[i-1][j][8]))*(dt/pow(dx,2.0))+(Dinsed[i][j][8]*(HgIIpw[i][j+1][8]-2.0*HgIIpw[i][j][8]+HgIIpw[i][j-1][8]))*(dt/pow(dy,2.0))+((Dinsed[i][j][9]-Dinsed[i][j][8])*(HgIIpw[i][j][9]-HgIIpw[i][j][8]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][8]-Dinsed[i][j][8])*(HgIIpw[i+1][j][8]-HgIIpw[i][j][8]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][8]-Dinsed[i][j][8])*(HgIIpw[i][j+1][8]-HgIIpw[i][j][8]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][8]+= Kme*HgIIpw[i][j][8]*dt-Kdeme*MMHgpw[i][j][8]*dt+(Dorsed[i][j][8]*(((MMHgpw[i][j][9]-MMHgpw[i][j][8])/dz2)-((MMHgpw[i][j][8]-MMHgpw[i][j][8])/(7.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][8]*(MMHgpw[i+1][j][8]-2.0*MMHgpw[i][j][8]+MMHgpw[i-1][j][8]))*(dt/pow(dx,2.0))+(Dorsed[i][j][8]*(MMHgpw[i][j+1][8]-2.0*MMHgpw[i][j][8]+MMHgpw[i][j-1][8]))*(dt/pow(dy,2.0))+((Dorsed[i][j][9]-Dorsed[i][j][8])*(MMHgpw[i][j][9]-MMHgpw[i][j][8]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][8]-Dorsed[i][j][8])*(MMHgpw[i+1][j][8]-MMHgpw[i][j][8]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][8]-Dorsed[i][j][8])*(MMHgpw[i][j+1][8]-MMHgpw[i][j][8]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][8]+= 0.0; // mg/Kg
     }

     HgIIpw[i][j][7]=HgIIpw[i][j][8];
     MMHgpw[i][j][7]=MMHgpw[i][j][8];
     THgsed[i][j][7]=THgsed[i][j][8];
     HgIIpw[i][j][6]=HgIIpw[i][j][7];
     MMHgpw[i][j][6]=MMHgpw[i][j][7];
     THgsed[i][j][6]=THgsed[i][j][7];
     HgIIpw[i][j][5]=HgIIpw[i][j][6];
     MMHgpw[i][j][5]=MMHgpw[i][j][6];
     THgsed[i][j][5]=THgsed[i][j][6];
     HgIIpw[i][j][4]=HgIIpw[i][j][5];
     MMHgpw[i][j][4]=MMHgpw[i][j][5];
     THgsed[i][j][4]=THgsed[i][j][5];
     HgIIpw[i][j][3]=HgIIpw[i][j][4];
     MMHgpw[i][j][3]=MMHgpw[i][j][4];
     THgsed[i][j][3]=THgsed[i][j][4];
     HgIIpw[i][j][2]=HgIIpw[i][j][3];
     MMHgpw[i][j][2]=MMHgpw[i][j][3];
     THgsed[i][j][2]=THgsed[i][j][3];
     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];
     
     
     for(r=9; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }
     
     }
     else if(dz1+7.0*dz2+Totdep[i][j]<=0.000000 && dz1+8.0*dz2+Totdep[i][j]>0.000000){

     if(THgsedold[i][j][9]>0.000000){
         HgIIpw[i][j][9]+= Kdeme*MMHgpw[i][j][9]*dt-Kme*HgIIpw[i][j][9]*dt+(Dinsed[i][j][9]*(((HgIIpw[i][j][10]-HgIIpw[i][j][9])/dz2)-((HgIIpw[i][j][9]-HgIIpw[i][j][9])/(8.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][9]*(HgIIpw[i+1][j][9]-2.0*HgIIpw[i][j][9]+HgIIpw[i-1][j][9]))*(dt/pow(dx,2.0))+(Dinsed[i][j][9]*(HgIIpw[i][j+1][9]-2.0*HgIIpw[i][j][9]+HgIIpw[i][j-1][9]))*(dt/pow(dy,2.0))+((Dinsed[i][j][10]-Dinsed[i][j][9])*(HgIIpw[i][j][10]-HgIIpw[i][j][9]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][9]-Dinsed[i][j][9])*(HgIIpw[i+1][j][9]-HgIIpw[i][j][9]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][9]-Dinsed[i][j][9])*(HgIIpw[i][j+1][9]-HgIIpw[i][j][9]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][9]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][9]+= Kme*HgIIpw[i][j][9]*dt-Kdeme*MMHgpw[i][j][9]*dt+(Dorsed[i][j][9]*(((MMHgpw[i][j][10]-MMHgpw[i][j][9])/dz2)-((MMHgpw[i][j][9]-MMHgpw[i][j][9])/(8.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][9]*(MMHgpw[i+1][j][9]-2.0*MMHgpw[i][j][9]+MMHgpw[i-1][j][9]))*(dt/pow(dx,2.0))+(Dorsed[i][j][9]*(MMHgpw[i][j+1][9]-2.0*MMHgpw[i][j][9]+MMHgpw[i][j-1][9]))*(dt/pow(dy,2.0))+((Dorsed[i][j][10]-Dorsed[i][j][9])*(MMHgpw[i][j][10]-MMHgpw[i][j][9]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][9]-Dorsed[i][j][9])*(MMHgpw[i+1][j][9]-MMHgpw[i][j][9]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][9]-Dorsed[i][j][9])*(MMHgpw[i][j+1][9]-MMHgpw[i][j][9]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][9]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][9]+= -1.0*alfa*THgsed[i][j][9]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][9]+= Kdeme*MMHgpw[i][j][9]*dt-Kme*HgIIpw[i][j][9]*dt+(Dinsed[i][j][9]*(((HgIIpw[i][j][10]-HgIIpw[i][j][9])/dz2)-((HgIIpw[i][j][9]-HgIIpw[i][j][9])/(8.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][9]*(HgIIpw[i+1][j][9]-2.0*HgIIpw[i][j][9]+HgIIpw[i-1][j][9]))*(dt/pow(dx,2.0))+(Dinsed[i][j][9]*(HgIIpw[i][j+1][9]-2.0*HgIIpw[i][j][9]+HgIIpw[i][j-1][9]))*(dt/pow(dy,2.0))+((Dinsed[i][j][10]-Dinsed[i][j][9])*(HgIIpw[i][j][10]-HgIIpw[i][j][9]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][9]-Dinsed[i][j][9])*(HgIIpw[i+1][j][9]-HgIIpw[i][j][9]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][9]-Dinsed[i][j][9])*(HgIIpw[i][j+1][9]-HgIIpw[i][j][9]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][9]+= Kme*HgIIpw[i][j][9]*dt-Kdeme*MMHgpw[i][j][9]*dt+(Dorsed[i][j][9]*(((MMHgpw[i][j][10]-MMHgpw[i][j][9])/dz2)-((MMHgpw[i][j][9]-MMHgpw[i][j][9])/(8.0*dz2+dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][9]*(MMHgpw[i+1][j][9]-2.0*MMHgpw[i][j][9]+MMHgpw[i-1][j][9]))*(dt/pow(dx,2.0))+(Dorsed[i][j][9]*(MMHgpw[i][j+1][9]-2.0*MMHgpw[i][j][9]+MMHgpw[i][j-1][9]))*(dt/pow(dy,2.0))+((Dorsed[i][j][10]-Dorsed[i][j][9])*(MMHgpw[i][j][10]-MMHgpw[i][j][9]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][9]-Dorsed[i][j][9])*(MMHgpw[i+1][j][9]-MMHgpw[i][j][9]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][9]-Dorsed[i][j][9])*(MMHgpw[i][j+1][9]-MMHgpw[i][j][9]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][9]+= 0.0; // mg/Kg
     }

     HgIIpw[i][j][8]=HgIIpw[i][j][9];
     MMHgpw[i][j][8]=MMHgpw[i][j][9];
     THgsed[i][j][8]=THgsed[i][j][9];
     HgIIpw[i][j][7]=HgIIpw[i][j][8];
     MMHgpw[i][j][7]=MMHgpw[i][j][8];
     THgsed[i][j][7]=THgsed[i][j][8];
     HgIIpw[i][j][6]=HgIIpw[i][j][7];
     MMHgpw[i][j][6]=MMHgpw[i][j][7];
     THgsed[i][j][6]=THgsed[i][j][7];
     HgIIpw[i][j][5]=HgIIpw[i][j][6];
     MMHgpw[i][j][5]=MMHgpw[i][j][6];
     THgsed[i][j][5]=THgsed[i][j][6];
     HgIIpw[i][j][4]=HgIIpw[i][j][5];
     MMHgpw[i][j][4]=MMHgpw[i][j][5];
     THgsed[i][j][4]=THgsed[i][j][5];
     HgIIpw[i][j][3]=HgIIpw[i][j][4];
     MMHgpw[i][j][3]=MMHgpw[i][j][4];
     THgsed[i][j][3]=THgsed[i][j][4];
     HgIIpw[i][j][2]=HgIIpw[i][j][3];
     MMHgpw[i][j][2]=MMHgpw[i][j][3];
     THgsed[i][j][2]=THgsed[i][j][3];
     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }

     }
     else{

     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }


     HgIIpw[i][j][9]=HgIIpw[i][j][10];
     MMHgpw[i][j][9]=MMHgpw[i][j][10];
     THgsed[i][j][9]=THgsed[i][j][10];
     HgIIpw[i][j][8]=HgIIpw[i][j][9];
     MMHgpw[i][j][8]=MMHgpw[i][j][9];
     THgsed[i][j][8]=THgsed[i][j][9];
     HgIIpw[i][j][7]=HgIIpw[i][j][8];
     MMHgpw[i][j][7]=MMHgpw[i][j][8];
     THgsed[i][j][7]=THgsed[i][j][8];
     HgIIpw[i][j][6]=HgIIpw[i][j][7];
     MMHgpw[i][j][6]=MMHgpw[i][j][7];
     THgsed[i][j][6]=THgsed[i][j][7];
     HgIIpw[i][j][5]=HgIIpw[i][j][6];
     MMHgpw[i][j][5]=MMHgpw[i][j][6];
     THgsed[i][j][5]=THgsed[i][j][6];
     HgIIpw[i][j][4]=HgIIpw[i][j][5];
     MMHgpw[i][j][4]=MMHgpw[i][j][5];
     THgsed[i][j][4]=THgsed[i][j][5];
     HgIIpw[i][j][3]=HgIIpw[i][j][4];
     MMHgpw[i][j][3]=MMHgpw[i][j][4];
     THgsed[i][j][3]=THgsed[i][j][4];
     HgIIpw[i][j][2]=HgIIpw[i][j][3];
     MMHgpw[i][j][2]=MMHgpw[i][j][3];
     THgsed[i][j][2]=THgsed[i][j][3];
     HgIIpw[i][j][1]=HgIIpw[i][j][2];
     MMHgpw[i][j][1]=MMHgpw[i][j][2];
     THgsed[i][j][1]=THgsed[i][j][2];

     }

     for(r=1; r<=RL; r++){
     
     if(HgIIpw[i][j][r]<0.000000){
		HgIIpw[i][j][r]=0.0;
     }
     
     if(MMHgpw[i][j][r]<0.000000){
		MMHgpw[i][j][r]=0.0;
     }
     
     if(THgsed[i][j][r]<0.000000){
		THgsed[i][j][r]=0.0;
     }
     
     }

     }
     else{
     
     for(r=1; r<=RL; r++){
              
     HgIIpw[i][j][r]=0.0; // microg/m^3
     MMHgpw[i][j][r]=0.0; // microg/m^3
     THgsed[i][j][r]=0.0; // mg/Kg
     
     }

     }
     
     for(r=1; r<=RL; r++){
              
     THgsedold[i][j][r]=THgsed[i][j][r]; // mg/Kg

     }
         
     } 
  }
  
  for(i=1; i<=I; i++){
      for(j=1; j<=J; j++){
               
         pcarsed[i][j]=0.01*TOCsed[i][j]; // dimensionless
         kfinMMsed[i][j]=(AssFoodMM/(1.0-AssFoodMM))*(1.0/(pcarsed[i][j]*(pow(10.0,logKoc)-1.0)+1.0))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolip/pow(10.0,logKow))+(1.0/(pcarsed[i][j]*pow(10.0,logKoc)*(1.0-AssFoodMM)*gamfood)))); // 1/d
         kfegrMMsed[i][j]=(1.0/(plipFish*(pow(10.0,logKow)-1.0)+1.0))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolip/pow(10.0,logKow))+(1.0/(pcarsed[i][j]*pow(10.0,logKoc)*(1.0-AssFoodMM)*gamfood)))); // 1/d      
               
         for(k=1; k<=K; k++){  
        
         if(Rini[i][j][k]==Rbot){

           if(HgII[i][j][k]<=0.000000){
				logBCFII[i][j]=0.0;
           }
           else{
               logBCFII[i][j]=aBCF+bBCF*log10(HgII[i][j][k]*pow(10.0,-3.0)); // l/Kg
           }
           
           DietzooHgII[i][j]=1.0*(PHgII[i][j][k]/Wp1)*pow(10.0,9.0); // microg/Kg
           DietzooMMHg[i][j]=1.0*(PMMHg[i][j][k]/Wp1)*pow(10.0,9.0); // microg/Kg               
           ZHgIIre[i][j]+=(Wzoo*kzurII*HgII[i][j][k]*pow(10.0,-3.0))*(dt/24.0)-(kzexrII+kzgr)*ZHgIIre[i][j]*(dt/24.0); // microg
           ZHgIIGIT[i][j]+=(Wzoo*AssFoodzooII*kzinII*DietzooHgII[i][j]*pow(10.0,-3.0))*(dt/24.0)-(kzegII+kzgr)*ZHgIIGIT[i][j]*(dt/24.0);  // microg
           ZMMHgre[i][j]+=(Wzoo*kzurMM*MMHg[i][j][k]*pow(10.0,-3.0))*(dt/24.0)-(kzexrMM+kzgr)*ZMMHgre[i][j]*(dt/24.0); // microg
           ZMMHgGIT[i][j]+=(Wzoo*AssFoodzooMM*kzinMM*DietzooMMHg[i][j]*pow(10.0,-3.0))*(dt/24.0)-(kzegMM+kzgr)*ZMMHgGIT[i][j]*(dt/24.0);  // microg
           
           if(ZHgIIre[i][j]<=0.000000){
				ZHgIIre[i][j]=0.0;
           } 
	   
	       if(ZMMHgre[i][j]<=0.000000){
				ZMMHgre[i][j]=0.0;
	       }
           
           if(ZHgIIGIT[i][j]<=0.000000){
				ZHgIIGIT[i][j]=0.0;
           } 
	   
	       if(ZMMHgGIT[i][j]<=0.000000){
				ZMMHgGIT[i][j]=0.0;
	       }
           
           ZHgII[i][j]=(ZHgIIre[i][j]+ZHgIIGIT[i][j])*(1.0/Wzoo);  // microg/g
           ZMMHg[i][j]=(ZMMHgre[i][j]+ZMMHgGIT[i][j])*(1.0/Wzoo);  // microg/g
           
           if(ZHgII[i][j]<=0.000000){
				ZHgII[i][j]=0.0;
           } 
	   
	       if(ZMMHg[i][j]<=0.000000){
				ZMMHg[i][j]=0.0;
	       } 
           
           kfurII[i][j]=0.002*pow(Wfish,-1.0*kal)*pow(10.0,logBCFII[i][j]); // l/Kg*d
           kfexrII[i][j]=kfurII[i][j]/pow(10.0,logBCFII[i][j]); // 1/d
           DietHgII[i][j]=PrefZoo*ZHgII[i][j]*pow(10.0,3.0)+Prefsed*((1.0-kMM)*THgsed[i][j][1])*pow(10.0,-3.0); // microg/Kg
           DietMMHg[i][j]=PrefZoo*ZMMHg[i][j]*pow(10.0,3.0)+Prefsed*(kMM*THgsed[i][j][1])*pow(10.0,-3.0); // microg/Kg               
           
           FiHgIIre[i][j]+=(Wfish*kfurII[i][j]*HgII[i][j][k]*pow(10.0,-3.0))*(dt/24.0)-(kfexrII[i][j]+kfgr)*FiHgIIre[i][j]*(dt/24.0); // microg
           FiHgIIGIT[i][j]+=(Wfish*kfin*DietHgII[i][j])*(dt/24.0)-(kfegr+kfgr)*FiHgIIGIT[i][j]*(dt/24.0);  // microg
           FiMMHgre[i][j]+=(Wfish*kfurMM*MMHg[i][j][k]*pow(10.0,-3.0))*(dt/24.0)-(kfexrMM+kfgr+lambmet)*FiMMHgre[i][j]*(dt/24.0); // microg
           FiMMHgGIT[i][j]+=(Wfish*kfinMM*DietMMHg[i][j])*(dt/24.0)-(kfegrMM+kfgr+lambmet)*FiMMHgGIT[i][j]*(dt/24.0);   // microg 
           FiMMHgGITdet[i][j]+=(Wfish*kfinMMsed[i][j]*DietMMHg[i][j])*(dt/24.0)-(kfegrMMsed[i][j]+kfgr+lambmet)*FiMMHgGITdet[i][j]*(dt/24.0);   // microg 
           
           if(FiHgIIre[i][j]<=0.000000){
				FiHgIIre[i][j]=0.0;
           } 
	   
	       if(FiMMHgre[i][j]<=0.000000){
				FiMMHgre[i][j]=0.0;
	       }
           
           if(FiHgIIGIT[i][j]<=0.000000){
				FiHgIIGIT[i][j]=0.0;
           } 
	   
	       if(FiMMHgGIT[i][j]<=0.000000){
				FiMMHgGIT[i][j]=0.0;
	       }
	   
	       if(FiMMHgGITdet[i][j]<=0.000000){
				FiMMHgGITdet[i][j]=0.0;
	       }
           
           FiHgII[i][j]=(FiHgIIre[i][j]+FiHgIIGIT[i][j])*pow(10.0,-3.0)*(1.0/Wfish);  // mg/Kg
           FiMMHg[i][j]=(FiMMHgre[i][j]+FiMMHgGIT[i][j]+FiMMHgGITdet[i][j])*pow(10.0,-3.0)*(1.0/Wfish);  // mg/Kg
           
           if(FiHgII[i][j]<=0.000000){
				FiHgII[i][j]=0.0;
           } 
	   
	       if(FiMMHg[i][j]<=0.000000){
				FiMMHg[i][j]=0.0;
	       } 
           
        }
         
        if(n>T-1 && n<T1){    
        PHgIItmean[i][j][k]+=(PHgII[i][j][k]/(Wp1*pow(10.0,-6.0)))/(T*M);
        PMMHgtmean[i][j][k]+=(PMMHg[i][j][k]/(Wp1*pow(10.0,-6.0)))/(T*M);        
        }
        
        if(n>N-T && n<=N){    
        PHgIItmean2[i][j][k]+=(PHgII[i][j][k]/(Wp1*pow(10.0,-6.0)))/(T*M);
        PMMHgtmean2[i][j][k]+=(PMMHg[i][j][k]/(Wp1*pow(10.0,-6.0)))/(T*M);        
        }
        
        } 
        
        if(n>T-1 && n<T1){
        ZHgIItmean[i][j]+=ZHgII[i][j]/(T*M);
        ZMMHgtmean[i][j]+=ZMMHg[i][j]/(T*M);
        FiHgIItmean[i][j]+=FiHgII[i][j]/(T*M);
        FiMMHgtmean[i][j]+=FiMMHg[i][j]/(T*M);
        }
        
        if(n>N-T && n<=N){
        ZHgIItmean2[i][j]+=ZHgII[i][j]/(T*M);
        ZMMHgtmean2[i][j]+=ZMMHg[i][j]/(T*M);
        FiHgIItmean2[i][j]+=FiHgII[i][j]/(T*M);
        FiMMHgtmean2[i][j]+=FiMMHg[i][j]/(T*M);
        }
        
     } 
  }  
         
   if(n==1 || n==3 || n==5 || n==7 || n==8 || n==10 || n==13 || n==25 || n==50 || n==75 || n==100 || n==150 || n==200 || n==N){
     for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){ 
                 
            if(m%tempo==0){
				   fprintf(ftotdep,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, Totdep[i][j]);
				   fprintf(fZ,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, ZHgII[i][j], ZMMHg[i][j]);
				   fprintf(fFi,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, FiHgII[i][j], FiMMHg[i][j]);
            }       
                             
            
            for(r=1; r<=RL; r++){
            
                if(m%tempo==0){
                                        
                fprintf(fHgIIpw,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, HgIIpw[i][j][r]);
                fprintf(fMMHgpw,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, MMHgpw[i][j][r]); 
                fprintf(fTHgsed,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, THgsed[i][j][r]);
                
                } 
                
            } 
            
            for(k=1; k<=K; k++){
            
                if(m%tempo==0){
	               fprintf(fb1,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, b1[i][j][k]);
				   fprintf(fct,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, chlatot[i][j][k]);
				   fprintf(fR,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, R[i][j][k]);
				   fprintf(fI,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, It[i][j][k]);
				   fprintf(fHg0,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, Hg0[i][j][k]);
				   fprintf(fHgII,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, HgII[i][j][k]);
				   fprintf(fMMHg,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, MMHg[i][j][k]);
				   fprintf(fDHg,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, DHg[i][j][k]);
				   fprintf(fTHg,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, THg[i][j][k]);
			//	   fprintf(fSPM,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, SPM[i][j][k]*pow(10.0,6.0)); // SPM in mg/l
			       fprintf(fP,"%f\t%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, PHgII[i][j][k], PMMHg[i][j][k]);
                }          	
            }    
        }
     }
  }  
   
   
    for(i=0; i<=I; i++){ // rispetto allo spazio x
        for(j=0; j<=J; j++){ // rispetto allo spazio y 

        if(Rini[i][j][1]>=Rin){
               
               fluHg0z[i][j][0]=(Hggas*(Pr/det)*pow(10.0,-3.0)+MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])); // // microg/(m^2*h)
               fluHgIIz[i][j][0]=HgIIatm*(Pr/det)*pow(10.0,-3.0); // microg/(m^2*h)
               fluMMHgz[i][j][0]=MMHgatm*(Pr/det)*pow(10.0,-3.0); // microg/(m^2*h)
            //   fluSPMz[i][j][0]=phiSPMatm*pow(10.0,-6.0); // Kg*m/l*h
               flub1z[i][j][0]=0.0;
               fluRz[i][j][0]=0.0;
                               
        }
        else{
               fluHg0z[i][j][0]=(Hggas*(Pr/det))*pow(10.0,-3.0); // // microg/(m^2*h) 
               fluHgIIz[i][j][0]=HgIIatm*(Pr/det)*pow(10.0,-3.0); // microg/(m^2*h)
               fluMMHgz[i][j][0]=MMHgatm*(Pr/det)*pow(10.0,-3.0); // microg/(m^2*h)
            //   fluSPMz[i][j][0]=phiSPMatm*pow(10.0,-6.0); // Kg*m/l*h
               flub1z[i][j][0]=0.0;
               fluRz[i][j][0]=0.0;
        }

        }     
    }
    
    for(i=1; i<=I; i++){ // rispetto allo spazio x 
        for(k=1; k<=K; k++){ // rispetto allo spazio z 

         flub1x[i][0][k]=0.0;
         fluRx[i][0][k]=0.0;
         fluHg0x[i][0][k]=0.0; 
         fluHgIIx[i][0][k]=0.0;
         fluMMHgx[i][0][k]=0.0;
       //  fluSPMx[i][0][k]=0.0;
       //  fluSPMy[i][0][k]=0.0;
         flub1y[i][0][k]=0.0;
         fluRy[i][0][k]=0.0;
         fluHg0y[i][0][k]=0.0;
         fluHgIIy[i][0][k]=0.0;
         fluMMHgy[i][0][k]=0.0;
         
        } 
    }  
    
    for(j=0; j<=J; j++){ // rispetto allo spazio x 
        for(k=1; k<=K; k++){ // rispetto allo spazio z 

         flub1x[0][j][k]=0.0;
         fluRx[0][j][k]=0.0;
         fluHg0x[0][j][k]=0.0; 
         fluHgIIx[0][j][k]=0.0;
         fluMMHgx[0][j][k]=0.0;
        // fluSPMx[0][j][k]=0.0;
        // fluSPMy[0][j][k]=0.0;
         flub1y[0][j][k]=0.0;
         fluRy[0][j][k]=0.0;
         fluHg0y[0][j][k]=0.0;
         fluHgIIy[0][j][k]=0.0;
         fluMMHgy[0][j][k]=0.0;
         
        } 
    }
  
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
    
       if(Rini[i][j][1]==Rbot){
               
               flub1z[i][j][1]=0.0;
               fluRz[i][j][1]=0.0;
               fluHg0z[i][j][1]=-1.0*Hggas*(Pr/det)*pow(10.0,-3.0)-1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1]); // microg/(m^2*h)
               fluHgIIz[i][j][1]=-1.0*HgIIatm*(Pr/det)*pow(10.0,-3.0)-1.0*MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][1])+1.0*HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]; // microg/(m^2*h)
               fluMMHgz[i][j][1]=-1.0*MMHgatm*(Pr/det)*pow(10.0,-3.0)-1.0*MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][1])+1.0*MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]; // microg/(m^2*h)  
            //   fluSPMz[i][j][1]=-1.0*phiSPMatm*pow(10.0,-6.0)+dep[i][j]*SWsed[i][j]; // Kg*m/l*h       
                 
       }
       else if(Rini[i][j][1]==Rin && Rini[i][j][2]>=Rin){
            
               if(vz[i][j][1]>=0.000000){
               fluRz[i][j][1]=-1.0*Dzz*((R[i][j][2]-R[i][j][1])/dz);
               fluHg0z[i][j][1]=-1.0*Hggas*(Pr/det)*pow(10.0,-3.0)-1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])+vz[i][j][1]*(Hg0[i][j][1])-1.0*Dzz*((Hg0[i][j][2]-Hg0[i][j][1])/dz);
               fluHgIIz[i][j][1]=-1.0*HgIIatm*(Pr/det)*pow(10.0,-3.0)-1.0*Dzz*((HgII[i][j][2]-HgII[i][j][1])/dz);
               fluMMHgz[i][j][1]=-1.0*MMHgatm*(Pr/det)*pow(10.0,-3.0)-1.0*Dzz*((MMHg[i][j][2]-MMHg[i][j][1])/dz);
               }
               else if(vz[i][j][1]<0.000000){
               fluRz[i][j][1]=vz[i][j][1]*(R[i][j][2]-R[i][j][1])-1.0*Dzz*((R[i][j][2]-R[i][j][1])/dz);
               fluHg0z[i][j][1]=-1.0*Hggas*(Pr/det)*pow(10.0,-3.0)-1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])+vz[i][j][1]*(Hg0[i][j][2]-Hg0[i][j][1])-1.0*Dzz*((Hg0[i][j][2]-Hg0[i][j][1])/dz);
               fluHgIIz[i][j][1]=-1.0*HgIIatm*(Pr/det)*pow(10.0,-3.0)+vz[i][j][1]*(HgII[i][j][2]-HgII[i][j][1])-1.0*Dzz*((HgII[i][j][2]-HgII[i][j][1])/dz);
               fluMMHgz[i][j][1]=-1.0*MMHgatm*(Pr/det)*pow(10.0,-3.0)+vz[i][j][1]*(MMHg[i][j][2]-MMHg[i][j][1])-1.0*Dzz*((MMHg[i][j][2]-MMHg[i][j][1])/dz);
               }
               else{
               fluRz[i][j][1]=0.0;
               fluHg0z[i][j][1]=0.0;
               fluHgIIz[i][j][1]=0.0;
               fluMMHgz[i][j][1]=0.0;
               }  
                
               if(v1+vz[i][j][1]>=0.000000){
               flub1z[i][j][1]=-1.0*Dzz*((b1[i][j][2]-b1[i][j][1])/dz);
               }
               else if(v1+vz[i][j][1]<0.000000){
               flub1z[i][j][1]=(v1+vz[i][j][1])*(b1[i][j][2]-b1[i][j][1])-1.0*Dzz*((b1[i][j][2]-b1[i][j][1])/dz);
               }
               else{
               flub1z[i][j][1]=0.0;
               }  
               
            /*   if(ws+vz[i][j][1]>=0.000000){
               fluSPMz[i][j][1]=-1.0*phiSPMatm*pow(10.0,-6.0)-1.0*Dzz*((SPM[i][j][2]-SPM[i][j][1])/dz); // Kg*m/l*h
               }
               else if(ws+vz[i][j][1]<0.000000){
               fluSPMz[i][j][1]=-1.0*phiSPMatm*pow(10.0,-6.0)+(ws+vz[i][j][1])*(SPM[i][j][2]-SPM[i][j][1])-1.0*Dzz*((SPM[i][j][2]-SPM[i][j][1])/dz); // Kg*m/l*h
               }
               else{
               fluSPMz[i][j][1]=0.0;
               }*/
                                
       }
       else{
               fluHg0z[i][j][1]=0.0; // microg/(m^2*h) 
               fluHgIIz[i][j][1]=0.0; // microg/(m^2*h)
               fluMMHgz[i][j][1]=0.0; // microg/(m^2*h)
               //fluSPMz[i][j][1]=0.0;
               flub1z[i][j][1]=0.0;
               fluRz[i][j][1]=0.0;
       }
  
     }
   }
   
    for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=1; k<=K; k++){ // rispetto allo spazio z	
            
            if(Rini[i-1][j][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i+1][j][k]>=Rin && vx[i][j][k]>=0.000000){
			   flub1x[i][j][k]=vx[i][j][k]*(b1[i][j][k]-b1[i-1][j][k])-1.0*Dxx*((b1[i+1][j][k]-b1[i][j][k])/dx);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i][j][k]-R[i-1][j][k])-1.0*Dxx*((R[i+1][j][k]-R[i][j][k])/dx);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i][j][k]-Hg0[i-1][j][k])-1.0*Dxx*((Hg0[i+1][j][k]-Hg0[i][j][k])/dx);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i][j][k]-HgII[i-1][j][k])-1.0*Dxx*((HgII[i+1][j][k]-HgII[i][j][k])/dx);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i][j][k]-MMHg[i-1][j][k])-1.0*Dxx*((MMHg[i+1][j][k]-MMHg[i][j][k])/dx);
               //fluSPMx[i][j][k]=vx[i][j][k]*(SPM[i][j][k]-SPM[i-1][j][k])-1.0*Dxx*((SPM[i+1][j][k]-SPM[i][j][k])/dx);
            }
            else if(vx[i][j][k]<0.000000 && Rini[i-1][j][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i+1][j][k]>=Rin){   
           	   flub1x[i][j][k]=vx[i][j][k]*(b1[i+1][j][k]-b1[i][j][k])-1.0*Dxx*((b1[i+1][j][k]-b1[i][j][k])/dx);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i+1][j][k]-R[i][j][k])-1.0*Dxx*((R[i+1][j][k]-R[i][j][k])/dx);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i+1][j][k]-Hg0[i][j][k])-1.0*Dxx*((Hg0[i+1][j][k]-Hg0[i][j][k])/dx);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i+1][j][k]-HgII[i][j][k])-1.0*Dxx*((HgII[i+1][j][k]-HgII[i][j][k])/dx);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i+1][j][k]-MMHg[i][j][k])-1.0*Dxx*((MMHg[i+1][j][k]-MMHg[i][j][k])/dx);
               //fluSPMx[i][j][k]=vx[i][j][k]*(SPM[i+1][j][k]-SPM[i][j][k])-1.0*Dxx*((SPM[i+1][j][k]-SPM[i][j][k])/dx);
            }
            else if(Rini[i-1][j][k]<=0.000000 && Rini[i][j][k]>=Rin && Rini[i+1][j][k]>=Rin && vx[i][j][k]>=0.000000){
			   flub1x[i][j][k]=vx[i][j][k]*(b1[i][j][k])-1.0*Dxx*((b1[i+1][j][k]-b1[i][j][k])/dx);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i][j][k])-1.0*Dxx*((R[i+1][j][k]-R[i][j][k])/dx);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i][j][k])-1.0*Dxx*((Hg0[i+1][j][k]-Hg0[i][j][k])/dx);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i][j][k])-1.0*Dxx*((HgII[i+1][j][k]-HgII[i][j][k])/dx);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i][j][k])-1.0*Dxx*((MMHg[i+1][j][k]-MMHg[i][j][k])/dx);
               //fluSPMx[i][j][k]=vx[i][j][k]*(SPM[i][j][k])-1.0*Dxx*((SPM[i+1][j][k]-SPM[i][j][k])/dx);  
            }
            else if(Rini[i-1][j][k]<=0.000000 && Rini[i][j][k]>=Rin && Rini[i+1][j][k]>=Rin && vx[i][j][k]<0.000000){
			   flub1x[i][j][k]=vx[i][j][k]*(b1[i+1][j][k]-b1[i][j][k])-1.0*Dxx*((b1[i+1][j][k]-b1[i][j][k])/dx);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i+1][j][k]-R[i][j][k])-1.0*Dxx*((R[i+1][j][k]-R[i][j][k])/dx);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i+1][j][k]-Hg0[i][j][k])-1.0*Dxx*((Hg0[i+1][j][k]-Hg0[i][j][k])/dx);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i+1][j][k]-HgII[i][j][k])-1.0*Dxx*((HgII[i+1][j][k]-HgII[i][j][k])/dx);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i+1][j][k]-MMHg[i][j][k])-1.0*Dxx*((MMHg[i+1][j][k]-MMHg[i][j][k])/dx);
               //fluSPMx[i][j][k]=vx[i][j][k]*(SPM[i+1][j][k]-SPM[i][j][k])-1.0*Dxx*((SPM[i+1][j][k]-SPM[i][j][k])/dx);
            }
            else if(Rini[i-1][j][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i+1][j][k]<=0.000000 && vx[i][j][k]<=0.000000){
               flub1x[i][j][k]=vx[i][j][k]*(-b1[i][j][k]);
			   fluRx[i][j][k]=vx[i][j][k]*(-R[i][j][k]);
               fluHg0x[i][j][k]=vx[i][j][k]*(-Hg0[i][j][k]);
               fluHgIIx[i][j][k]=vx[i][j][k]*(-HgII[i][j][k]);
               fluMMHgx[i][j][k]=vx[i][j][k]*(-MMHg[i][j][k]);
               //fluSPMx[i][j][k]=vx[i][j][k]*(-SPM[i][j][k]);
            }
            else if(Rini[i-1][j][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i+1][j][k]<=0.000000 && vx[i][j][k]>0.000000){
               flub1x[i][j][k]=vx[i][j][k]*(b1[i][j][k]-b1[i-1][j][k]);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i][j][k]-R[i-1][j][k]);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i][j][k]-Hg0[i-1][j][k]);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i][j][k]-HgII[i-1][j][k]);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i][j][k]-MMHg[i-1][j][k]);
               //fluSPMx[i][j][k]=vx[i][j][k]*(SPM[i][j][k]-SPM[i-1][j][k]);
            }
            else{
               flub1x[i][j][k]=0.0;
			   fluRx[i][j][k]=0.0;
               fluHg0x[i][j][k]=0.0;
               fluHgIIx[i][j][k]=0.0;
               fluMMHgx[i][j][k]=0.0;
               //fluSPMx[i][j][k]=0.0;
            }  
                  
            }
        }
    }    
                         
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=1; k<=K; k++){ // rispetto allo spazio z	     
            
            if(Rini[i][j-1][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i][j+1][k]>=Rin && vy[i][j][k]>=0.000000){
			   flub1y[i][j][k]=vy[i][j][k]*(b1[i][j][k]-b1[i][j-1][k])-1.0*Dyy*((b1[i][j+1][k]-b1[i][j][k])/dy);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j][k]-R[i][j-1][k])-1.0*Dyy*((R[i][j+1][k]-R[i][j][k])/dy);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j][k]-Hg0[i][j-1][k])-1.0*Dyy*((Hg0[i][j+1][k]-Hg0[i][j][k])/dy);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j][k]-HgII[i][j-1][k])-1.0*Dyy*((HgII[i][j+1][k]-HgII[i][j][k])/dy);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j][k]-MMHg[i][j-1][k])-1.0*Dyy*((MMHg[i][j+1][k]-MMHg[i][j][k])/dy);
               //fluSPMy[i][j][k]=vy[i][j][k]*(SPM[i][j][k]-SPM[i][j-1][k])-1.0*Dyy*((SPM[i][j+1][k]-SPM[i][j][k])/dy);
            }
            else if(vy[i][j][k]<0.000000 && Rini[i][j-1][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i][j+1][k]>=Rin){   
           	   flub1y[i][j][k]=vy[i][j][k]*(b1[i][j+1][k]-b1[i][j][k])-1.0*Dyy*((b1[i][j+1][k]-b1[i][j][k])/dy);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j+1][k]-R[i][j][k])-1.0*Dyy*((R[i][j+1][k]-R[i][j][k])/dy);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j+1][k]-Hg0[i][j][k])-1.0*Dyy*((Hg0[i][j+1][k]-Hg0[i][j][k])/dy);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j+1][k]-HgII[i][j][k])-1.0*Dyy*((HgII[i][j+1][k]-HgII[i][j][k])/dy);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j+1][k]-MMHg[i][j][k])-1.0*Dyy*((MMHg[i][j+1][k]-MMHg[i][j][k])/dy);
               //fluSPMy[i][j][k]=vy[i][j][k]*(SPM[i][j+1][k]-SPM[i][j][k])-1.0*Dyy*((SPM[i][j+1][k]-SPM[i][j][k])/dy);
            }
            else if(Rini[i][j-1][k]<=0.000000 && Rini[i][j][k]>=Rin && Rini[i][j+1][k]>=Rin && vy[i][j][k]>=0.000000){
			   flub1y[i][j][k]=vy[i][j][k]*(b1[i][j][k])-1.0*Dyy*((b1[i][j+1][k]-b1[i][j][k])/dy);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j][k])-1.0*Dyy*((R[i][j+1][k]-R[i][j][k])/dy);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j][k])-1.0*Dyy*((Hg0[i][j+1][k]-Hg0[i][j][k])/dy);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j][k])-1.0*Dyy*((HgII[i][j+1][k]-HgII[i][j][k])/dy);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j][k])-1.0*Dyy*((MMHg[i][j+1][k]-MMHg[i][j][k])/dy);
               //fluSPMy[i][j][k]=vy[i][j][k]*(SPM[i][j][k])-1.0*Dyy*((SPM[i][j+1][k]-SPM[i][j][k])/dy);  
            }
            else if(Rini[i][j-1][k]<=0.000000 && Rini[i][j][k]>=Rin && Rini[i][j+1][k]>=Rin && vy[i][j][k]<0.000000){
			   flub1y[i][j][k]=vy[i][j][k]*(b1[i][j+1][k]-b1[i][j][k])-1.0*Dyy*((b1[i][j+1][k]-b1[i][j][k])/dy);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j+1][k]-R[i][j][k])-1.0*Dyy*((R[i][j+1][k]-R[i][j][k])/dy);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j+1][k]-Hg0[i][j][k])-1.0*Dyy*((Hg0[i][j+1][k]-Hg0[i][j][k])/dy);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j+1][k]-HgII[i][j][k])-1.0*Dyy*((HgII[i][j+1][k]-HgII[i][j][k])/dy);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j+1][k]-MMHg[i][j][k])-1.0*Dyy*((MMHg[i][j+1][k]-MMHg[i][j][k])/dy);
               //fluSPMy[i][j][k]=vy[i][j][k]*(SPM[i][j+1][k]-SPM[i][j][k])-1.0*Dyy*((SPM[i][j+1][k]-SPM[i][j][k])/dy);
            }
            else if(Rini[i][j-1][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i][j+1][k]<=0.000000 && vy[i][j][k]<=0.000000){
               flub1y[i][j][k]=vy[i][j][k]*(-b1[i][j][k]);
			   fluRy[i][j][k]=vy[i][j][k]*(-R[i][j][k]);
               fluHg0y[i][j][k]=vy[i][j][k]*(-Hg0[i][j][k]);
               fluHgIIy[i][j][k]=vy[i][j][k]*(-HgII[i][j][k]);
               fluMMHgy[i][j][k]=vy[i][j][k]*(-MMHg[i][j][k]);
               //fluSPMy[i][j][k]=vy[i][j][k]*(-SPM[i][j][k]);  
            }
            else if(Rini[i][j-1][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i][j+1][k]<=0.000000 && vy[i][j][k]>0.000000){
               flub1y[i][j][k]=vy[i][j][k]*(b1[i][j][k]-b1[i][j-1][k]);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j][k]-R[i][j-1][k]);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j][k]-Hg0[i][j-1][k]);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j][k]-HgII[i][j-1][k]);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j][k]-MMHg[i][j-1][k]);
               //fluSPMy[i][j][k]=vy[i][j][k]*(SPM[i][j][k]-SPM[i][j-1][k]);
            }
            else{
               flub1y[i][j][k]=0.0;
			   fluRy[i][j][k]=0.0;
               fluHg0y[i][j][k]=0.0;
               fluHgIIy[i][j][k]=0.0;
               fluMMHgy[i][j][k]=0.0;
               //fluSPMy[i][j][k]=0.0;
            }  
      
            }
        }
    }
    
    for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=2; k<=K; k++){ // rispetto allo spazio z	     
       
            if(Rini[i][j][k]==Rbot){
			   fluRz[i][j][k]=0.0;
               fluHg0z[i][j][k]=0.0;
               fluHgIIz[i][j][k]=-1.0*MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])+1.0*HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]; // microg/(m^2*h)
               fluMMHgz[i][j][k]=-1.0*MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])+1.0*MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]; // microg/(m^2*h)  
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin &&  vz[i][j][k]>=0.000000){
			   fluRz[i][j][k]=vz[i][j][k]*(R[i][j][k]-R[i][j][k-1])-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*(Hg0[i][j][k]-Hg0[i][j][k-1])-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*(HgII[i][j][k]-HgII[i][j][k-1])-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*(MMHg[i][j][k]-MMHg[i][j][k-1])-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);		   
	        }
	        else if(vz[i][j][k]<0.000000 && Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin){ 
			   fluRz[i][j][k]=vz[i][j][k]*(R[i][j][k+1]-R[i][j][k])-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*(Hg0[i][j][k+1]-Hg0[i][j][k])-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*(HgII[i][j][k+1]-HgII[i][j][k])-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*(MMHg[i][j][k+1]-MMHg[i][j][k])-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);
	        }
            else if(Rini[i][j][k-1]<=0.000000 && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && vz[i][j][k]<0.000000){
			   fluRz[i][j][k]=vz[i][j][k]*(R[i][j][k+1]-R[i][j][k])-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*(Hg0[i][j][k+1]-Hg0[i][j][k])-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*(HgII[i][j][k+1]-HgII[i][j][k])-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*(MMHg[i][j][k+1]-MMHg[i][j][k])-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);
            }
            else if(Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && vz[i][j][k]<=0.000000){
			   fluRz[i][j][k]=vz[i][j][k]*((R[i][j][k+1]-R[i][j][k]))-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*((Hg0[i][j][k+1]-Hg0[i][j][k]))-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*((HgII[i][j][k+1]-HgII[i][j][k]))-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*((MMHg[i][j][k+1]-MMHg[i][j][k]))-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && vz[i][j][k]>0.000000){
			   fluRz[i][j][k]=vz[i][j][k]*(R[i][j][k]-R[i][j][k-1])-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*(Hg0[i][j][k]-Hg0[i][j][k-1])-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*(HgII[i][j][k]-HgII[i][j][k-1])-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*(MMHg[i][j][k]-MMHg[i][j][k-1])-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);
            }
            else{
			   fluRz[i][j][k]=0.0;
               fluHg0z[i][j][k]=0.0;
               fluHgIIz[i][j][k]=0.0;
               fluMMHgz[i][j][k]=0.0;
            }  
             
            }
        }
    } 

    for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=2; k<=K; k++){ // rispetto allo spazio z	     
       
            if(Rini[i][j][k]==Rbot){
               flub1z[i][j][k]=0.0;
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && (v1+vz[i][j][k]>=0.000000)){
			   flub1z[i][j][k]=(v1+vz[i][j][k])*(b1[i][j][k]-b1[i][j][k-1])-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz); 
	        }
	        else if((v1+vz[i][j][k]<0.000000) && Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin){
           	   flub1z[i][j][k]=(v1+vz[i][j][k])*(b1[i][j][k+1]-1.0*b1[i][j][k])-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz);
	        }
            else if(Rini[i][j][k-1]<=0.000000 && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && (v1+vz[i][j][k]<0.000000)){
			   flub1z[i][j][k]=(v1+vz[i][j][k])*(b1[i][j][k+1]-1.0*b1[i][j][k])-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz);
            }
            else if(Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && (v1+vz[i][j][k]<=0.000000)){
               flub1z[i][j][k]=(v1+vz[i][j][k])*((b1[i][j][k+1]-b1[i][j][k]))-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz);
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && (v1+vz[i][j][k]>0.000000)){
                flub1z[i][j][k]=(v1+vz[i][j][k])*(b1[i][j][k]-b1[i][j][k-1])-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz); 
            }
            else{
               flub1z[i][j][k]=0.0;
            }  

            }
        }
    }

//%%%%%%%%%%%%%%%%% Subroutine da inserire solo se SPM è variabile nel tempo e nello spazio %%%%%%%%%%%%%%%%%%%%%%   

  /*  for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=2; k<=K; k++){ // rispetto allo spazio z	     
            
            if(Rini[i][j][k]==Rbot){
               fluSPMz[i][j][k]=dep[i][j]*SWsed[i][j]; //m*Kg/l*h
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && (ws+vz[i][j][k]>=0.000000)){
			   fluSPMz[i][j][k]=(ws+vz[i][j][k])*(SPM[i][j][k]-1.0*SPM[i][j][k-1])-1.0*Dzz*((SPM[i][j][k+1]-SPM[i][j][k])/dz);   
	        }
	        else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && (ws+vz[i][j][k]<0.000000)){
           	   fluSPMz[i][j][k]=(ws+vz[i][j][k])*(SPM[i][j][k+1]-1.0*SPM[i][j][k])-1.0*Dzz*((SPM[i][j][k+1]-SPM[i][j][k])/dz);
	        }
            else if(Rini[i][j][k-1]<=0.000000 && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && (ws+vz[i][j][k]<0.000000)){
               fluSPMz[i][j][k]=(ws+vz[i][j][k])*(SPM[i][j][k+1]-1.0*SPM[i][j][k])-1.0*Dzz*((SPM[i][j][k+1]-SPM[i][j][k])/dz);
            }
            else if(Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && (ws+vz[i][j][k]<=0.000000)){
               fluSPMz[i][j][k]=(ws+vz[i][j][k])*((SPM[i][j][k+1]-SPM[i][j][k]))-1.0*Dzz*((SPM[i][j][k+1]-SPM[i][j][k])/dz);  
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && (ws+vz[i][j][k]>0.000000)){
               fluSPMz[i][j][k]=(ws+vz[i][j][k])*(SPM[i][j][k]-1.0*SPM[i][j][k-1])-1.0*Dzz*((SPM[i][j][k+1]-SPM[i][j][k])/dz);
            }
            else{
               fluSPMz[i][j][k]=0.0;
            }  
                 
            }
        }
    } */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

 //%%%%%%%%%%%%%%%%%%%%%Queste subroutine dipendono dalla forma e dal posizionamento degli inlets dei SIN %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
   
   for(k=1; k<=klev; k++){ // rispetto allo spazio z
   
      if(k==1){
               
            if(vx[I][L][k]<=0.000000){
               sumfluHg0x[I][L]=vx[I][L][k]*(0.2*DHgexts27)-1.0*Dxx*((0.2*DHgexts27-Hg0[I][L][k])/dx);
               sumfluHgIIx[I][L]=vx[I][L][k]*(0.794*DHgexts27)-1.0*Dxx*((0.794*DHgexts27-HgII[I][L][k])/dx);
               sumfluMMHgx[I][L]=vx[I][L][k]*(0.006*DHgexts27)-1.0*Dxx*((0.006*DHgexts27-MMHg[I][L][k])/dx);
               sumfluTHgx[I][L]=vx[I][L][k]*(THgexts27)-1.0*Dxx*((THgexts27-THg[I][L][k])/dx);
            }
            else{                                       
               sumfluHg0x[I][L]=vx[I][L][k]*(Hg0[I][L][k])-1.0*Dxx*((0.2*DHgexts27-Hg0[I][L][k])/dx);
               sumfluHgIIx[I][L]=vx[I][L][k]*(HgII[I][L][k])-1.0*Dxx*((0.794*DHgexts27-HgII[I][L][k])/dx);
               sumfluMMHgx[I][L]=vx[I][L][k]*(MMHg[I][L][k])-1.0*Dxx*((0.006*DHgexts27-MMHg[I][L][k])/dx);
               sumfluTHgx[I][L]=vx[I][L][k]*(THg[I][L][k])-1.0*Dxx*((THgexts27-THg[I][L][k])/dx); 
            }   
            
      }
      else{
           
            if(vx[I][L][k]<=0.000000){
               sumfluHg0x[I][L]+=vx[I][L][k]*(0.2*DHgexts27)-1.0*Dxx*((0.2*DHgexts27-Hg0[I][L][k])/dx);
               sumfluHgIIx[I][L]+=vx[I][L][k]*(0.794*DHgexts27)-1.0*Dxx*((0.794*DHgexts27-HgII[I][L][k])/dx);
               sumfluMMHgx[I][L]+=vx[I][L][k]*(0.006*DHgexts27)-1.0*Dxx*((0.006*DHgexts27-MMHg[I][L][k])/dx);
               sumfluTHgx[I][L]+=vx[I][L][k]*(THgexts27)-1.0*Dxx*((THgexts27-THg[I][L][k])/dx);
            }
            else{                                       
               sumfluHg0x[I][L]+=vx[I][L][k]*(Hg0[I][L][k])-1.0*Dxx*((0.2*DHgexts27-Hg0[I][L][k])/dx);
               sumfluHgIIx[I][L]+=vx[I][L][k]*(HgII[I][L][k])-1.0*Dxx*((0.794*DHgexts27-HgII[I][L][k])/dx);
               sumfluMMHgx[I][L]+=vx[I][L][k]*(MMHg[I][L][k])-1.0*Dxx*((0.006*DHgexts27-MMHg[I][L][k])/dx);
               sumfluTHgx[I][L]+=vx[I][L][k]*(THg[I][L][k])-1.0*Dxx*((THgexts27-THg[I][L][k])/dx);
            }  
            
      }
   
   }
   
   fluHg0xlev=Llev*sumfluHg0x[I][L]*dz;
   fluHgIIxlev=Llev*sumfluHgIIx[I][L]*dz;
   fluMMHgxlev=Llev*sumfluMMHgx[I][L]*dz;
   fluTHgxlev=Llev*sumfluTHgx[I][L]*dz;
   
 
   for(k=1; k<=ksci; k++){ // rispetto allo spazio z
   
      if(k==1){
               
            if(vy[C][J][k]<=0.000000){
               sumfluHg0y[C][J]=vy[C][J][k]*(0.2*DHgextb26)-1.0*Dyy*((0.2*DHgextb26-Hg0[C][J][k])/dy);
               sumfluHgIIy[C][J]=vy[C][J][k]*(0.794*DHgextb26)-1.0*Dyy*((0.794*DHgextb26-HgII[C][J][k])/dy);
               sumfluMMHgy[C][J]=vy[C][J][k]*(0.006*DHgextb26)-1.0*Dyy*((0.006*DHgextb26-MMHg[C][J][k])/dy);
               sumfluTHgy[C][J]=vy[C][J][k]*(THgexts26)-1.0*Dyy*((THgexts26-THg[C][J][k])/dy);
            }
            else{                                       
               sumfluHg0y[C][J]=vy[C][J][k]*(Hg0[C][J][k])-1.0*Dyy*((0.2*DHgextm26-Hg0[C][J][k])/dy);
               sumfluHgIIy[C][J]=vy[C][J][k]*(HgII[C][J][k])-1.0*Dyy*((0.794*DHgextm26-HgII[C][J][k])/dy);
               sumfluMMHgy[C][J]=vy[C][J][k]*(MMHg[C][J][k])-1.0*Dyy*((0.006*DHgextm26-MMHg[C][J][k])/dy);
               sumfluTHgy[C][J]=vy[C][J][k]*(THg[C][J][k])-1.0*Dyy*((THgexts26-THg[C][J][k])/dy);  
            }  
               
            if(vx[C][J][k]<=0.000000){
               sumfluHg0xs[C][J]=vx[C][J][k]*(Hg0[C+1][J][k])-1.0*Dxx*((Hg0[C+1][J][k]-Hg0[C][J][k])/dx);
               sumfluHgIIxs[C][J]=vx[C][J][k]*(HgII[C+1][J][k])-1.0*Dxx*((HgII[C+1][J][k]-HgII[C][J][k])/dx);
               sumfluMMHgxs[C][J]=vx[C][J][k]*(MMHg[C+1][J][k])-1.0*Dxx*((MMHg[C+1][J][k]-MMHg[C][J][k])/dx);
               sumfluTHgxs[C][J]=vx[C][J][k]*(THg[C+1][J][k])-1.0*Dxx*((THg[C+1][J][k]-THg[C][J][k])/dx);
            }
            else{                                       
               sumfluHg0xs[C][J]=vx[C][J][k]*(Hg0[C][J][k])-1.0*Dxx*((Hg0[C+1][J][k]-Hg0[C][J][k])/dx);
               sumfluHgIIxs[C][J]=vx[C][J][k]*(HgII[C][J][k])-1.0*Dxx*((HgII[C+1][J][k]-HgII[C][J][k])/dx);
               sumfluMMHgxs[C][J]=vx[C][J][k]*(MMHg[C][J][k])-1.0*Dxx*((MMHg[C+1][J][k]-MMHg[C][J][k])/dx);
               sumfluTHgxs[C][J]=vx[C][J][k]*(THg[C][J][k])-1.0*Dxx*((THg[C+1][J][k]-THg[C][J][k])/dx);
            }
            
      }
      else{
           
            if(vy[C][J][k]<=0.000000){
               sumfluHg0y[C][J]+=vy[C][J][k]*(0.2*DHgextb26)-1.0*Dyy*((0.2*DHgextb26-Hg0[C][J][k])/dy);
               sumfluHgIIy[C][J]+=vy[C][J][k]*(0.794*DHgextb26)-1.0*Dyy*((0.794*DHgextb26-HgII[C][J][k])/dy);
               sumfluMMHgy[C][J]+=vy[C][J][k]*(0.006*DHgextb26)-1.0*Dyy*((0.006*DHgextb26-MMHg[C][J][k])/dy);
               sumfluTHgy[C][J]+=vy[C][J][k]*(THgexts26)-1.0*Dyy*((THgexts26-THg[C][J][k])/dy);
            }
            else{                                       
               sumfluHg0y[C][J]+=vy[C][J][k]*(Hg0[C][J][k])-1.0*Dyy*((0.2*DHgextm26-Hg0[C][J][k])/dy);
               sumfluHgIIy[C][J]+=vy[C][J][k]*(HgII[C][J][k])-1.0*Dyy*((0.794*DHgextm26-HgII[C][J][k])/dy);
               sumfluMMHgy[C][J]+=vy[C][J][k]*(MMHg[C][J][k])-1.0*Dyy*((0.006*DHgextm26-MMHg[C][J][k])/dy);
               sumfluTHgy[C][J]+=vy[C][J][k]*(THg[C][J][k])-1.0*Dyy*((THgexts26-THg[C][J][k])/dy);
            }  
               
            if(vx[C][J][k]<=0.000000){
               sumfluHg0xs[C][J]+=vx[C][J][k]*(Hg0[C+1][J][k])-1.0*Dxx*((Hg0[C+1][J][k]-Hg0[C][J][k])/dx);
               sumfluHgIIxs[C][J]+=vx[C][J][k]*(HgII[C+1][J][k])-1.0*Dxx*((HgII[C+1][J][k]-HgII[C][J][k])/dx);
               sumfluMMHgxs[C][J]+=vx[C][J][k]*(MMHg[C+1][J][k])-1.0*Dxx*((MMHg[C+1][J][k]-MMHg[C][J][k])/dx);
               sumfluTHgxs[C][J]+=vx[C][J][k]*(THg[C+1][J][k])-1.0*Dxx*((THg[C+1][J][k]-THg[C][J][k])/dx);
            }
            else{                                       
               sumfluHg0xs[C][J]+=vx[C][J][k]*(Hg0[C][J][k])-1.0*Dxx*((Hg0[C+1][J][k]-Hg0[C][J][k])/dx);
               sumfluHgIIxs[C][J]+=vx[C][J][k]*(HgII[C][J][k])-1.0*Dxx*((HgII[C+1][J][k]-HgII[C][J][k])/dx);
               sumfluMMHgxs[C][J]+=vx[C][J][k]*(MMHg[C][J][k])-1.0*Dxx*((MMHg[C+1][J][k]-MMHg[C][J][k])/dx);
               sumfluTHgxs[C][J]+=vx[C][J][k]*(THg[C][J][k])-1.0*Dxx*((THg[C+1][J][k]-THg[C][J][k])/dx);
            }
      }
      
   }
   
   fluHg0ysci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluHg0y[C][J]*dz;
   fluHgIIysci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluHgIIy[C][J]*dz;
   fluMMHgysci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluMMHgy[C][J]*dz;
   fluTHgysci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluTHgy[C][J]*dz;
   fluHg0xsci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluHg0xs[C][J]*dz;
   fluHgIIxsci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluHgIIxs[C][J]*dz;
   fluMMHgxsci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluMMHgxs[C][J]*dz;
   fluTHgxsci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluTHgxs[C][J]*dz;
   
 //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluxHgIIsed[i][j] = MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*24.0-HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*24.0; // microg/m^2*d
               fluxMMHgsed[i][j] = MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*24.0-MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*24.0; // microg/m^2*d    
           }
            
           }
       }
   }
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][1]>=Rin){
               fluxHg0atm[i][j] = -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10.0,3.0); // ng/m^2*h
               fluxHg0dep[i][j] = Hggas*(Pr/det); // ng/m^2*h
               fluxHgIIdep[i][j] = HgIIatm*(Pr/det); // ng/m^2*h  
               fluxMMHgdep[i][j] = MMHgatm*(Pr/det); // ng/m^2*h 
           }
           else{
               fluxHg0atm[i][j] = 0.0; // ng/m^2*h
               fluxHg0dep[i][j] = 0.0; // ng/m^2*h
               fluxHgIIdep[i][j] = 0.0; // ng/m^2*h
               fluxMMHgdep[i][j] = 0.0; // ng/m^2*h
           }

           }
       }
   }
  
    if(n==1 || n==3 || n==5 || n==7 || n==8 || n==10 || n==13 || n==25 || n==50 || n==75 || n==100 || n==150 || n==200 || n==N){
     for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
                 
           if(m%tempo==0){  
                 fprintf(fHgIIfluxsed,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxHgIIsed[i][j]);
                 fprintf(fMMHgfluxsed,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxMMHgsed[i][j]); 
                 fprintf(fHg0fluxatm,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxHg0atm[i][j]);
                 fprintf(fHg0fluxdep,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxHg0dep[i][j]);
                 fprintf(fHgIIfluxdep,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxHgIIdep[i][j]);
                 fprintf(fMMHgfluxdep,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxMMHgdep[i][j]);
           }      
                  
        }
     }
  }   
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Queste variabili dipendono dalla forma del bacino%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
   
    fluHgIIzsed=0.0;
    fluMMHgzsed=0.0;
    fluHgIIzbur=0.0;
    fluMMHgzbur=0.0;
    fluHgIIzsedext1=0.0;
    fluMMHgzsedext1=0.0;
    fluHgIIzburext1=0.0;
    fluMMHgzburext1=0.0;
    fluHgIIzsedext2=0.0;
    fluMMHgzsedext2=0.0;
    fluHgIIzburext2=0.0;
    fluMMHgzburext2=0.0;
    fluHgIIzsedext3=0.0;
    fluMMHgzsedext3=0.0;
    fluHgIIzburext3=0.0;
    fluMMHgzburext3=0.0;
    fluxHg0zatm=0.0;
    fluxHg0zdep=0.0;
    fluxHgIIzdep=0.0;
    fluxMMHgzdep=0.0;
    fluxSPMzdep=0.0;
    fluxHg0zatmext1=0.0;
    fluxHg0zdepext1=0.0;
    fluxHgIIzdepext1=0.0;
    fluxMMHgzdepext1=0.0;
    fluxSPMzdepext1=0.0;
    fluxHg0zatmext2=0.0;
    fluxHg0zdepext2=0.0;
    fluxHgIIzdepext2=0.0;
    fluxMMHgzdepext2=0.0;
    fluxSPMzdepext2=0.0;
    fluxHg0zatmext3=0.0;
    fluxHg0zdepext3=0.0;
    fluxHgIIzdepext3=0.0;
    fluxMMHgzdepext3=0.0;
    fluxSPMzdepext3=0.0;
    
    
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluHgIIzsed += MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*dx*dy-HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluMMHgzsed += MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*dx*dy-MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h   
               fluHgIIzbur += HgIIpw[i][j][1]*kDIIsed*SWsed[i][j]*dep[i][j]*dx*dy+HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluMMHgzbur += MMHgpw[i][j][1]*kDMMsed*SWsed[i][j]*dep[i][j]*dx*dy+MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
           }
           else{
               fluHgIIzsed += 0.0;
               fluMMHgzsed += 0.0;
               fluHgIIzbur += 0.0; // microg/h
               fluMMHgzbur += 0.0; // microg/h
           } 
           
           if(Rini[i][j][1]>=Rin && Rini[i][j][k]==Rbot){
               fluxHg0zatm += -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10.0,3.0)*dx*dy; // ng/h
               fluxHg0zdep += Hggas*(Pr/det)*dx*dy; // ng/h
               fluxHgIIzdep += HgIIatm*(Pr/det)*dx*dy; // ng/h  
               fluxMMHgzdep += MMHgatm*(Pr/det)*dx*dy; // ng/h 
               fluxSPMzdep += phiSPMatm*pow(10.0,-3.0)*dx*dy; // Kg/h
           }
           else{
               fluxHg0zatm += 0.0; // ng/h
               fluxHg0zdep += 0.0; // ng/h
               fluxHgIIzdep += 0.0; // ng/h
               fluxMMHgzdep += 0.0; // ng/h
               fluxSPMzdep += 0.0; // Kg/h
           }
           
           }
       }
   }
   
   
   for(i=iext1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=jext1; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluHgIIzsedext1 += MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*dx*dy-HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluMMHgzsedext1 += MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*dx*dy-MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h 
               fluHgIIzburext1 += HgIIpw[i][j][1]*kDIIsed*SWsed[i][j]*dep[i][j]*dx*dy+HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluMMHgzburext1 += MMHgpw[i][j][1]*kDMMsed*SWsed[i][j]*dep[i][j]*dx*dy+MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
           }
           else{
               fluHgIIzsedext1 += 0.0;
               fluMMHgzsedext1 += 0.0;
               fluHgIIzburext1 += 0.0; // microg/h
               fluMMHgzburext1 += 0.0; // microg/h
           }
           
           if(Rini[i][j][1]>=Rin && Rini[i][j][k]==Rbot){
               fluxHg0zatmext1 += -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10.0,3.0)*dx*dy; // ng/h
               fluxHg0zdepext1 += Hggas*(Pr/det)*dx*dy; // ng/h
               fluxHgIIzdepext1 += HgIIatm*(Pr/det)*dx*dy; // ng/h  
               fluxMMHgzdepext1 += MMHgatm*(Pr/det)*dx*dy; // ng/h 
               fluxSPMzdepext1 += phiSPMatm*pow(10.0,-3.0)*dx*dy; // Kg/h
           }
           else{
               fluxHg0zatmext1 += 0.0; // ng/h
               fluxHg0zdepext1 += 0.0; // ng/h
               fluxHgIIzdepext1 += 0.0; // ng/h
               fluxMMHgzdepext1 += 0.0; // ng/h
               fluxSPMzdepext1 += 0.0; // Kg/h
           }
           
           }
       }
   }
   
   for(i=iext2; i<=I; i++){ // rispetto allo spazio x
       for(j=jext2; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluHgIIzsedext2 += MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*dx*dy-HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluMMHgzsedext2 += MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*dx*dy-MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h 
               fluHgIIzburext2 += HgIIpw[i][j][1]*kDIIsed*SWsed[i][j]*dep[i][j]*dx*dy+HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluMMHgzburext2 += MMHgpw[i][j][1]*kDMMsed*SWsed[i][j]*dep[i][j]*dx*dy+MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
           }
           else{
               fluHgIIzsedext2 += 0.0;
               fluMMHgzsedext2 += 0.0;
               fluHgIIzburext2 += 0.0; // microg/h
               fluMMHgzburext2 += 0.0; // microg/h
           } 
           
           if(Rini[i][j][1]>=Rin && Rini[i][j][k]==Rbot){
               fluxHg0zatmext2 += -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10.0,3.0)*dx*dy; // ng/h
               fluxHg0zdepext2 += Hggas*(Pr/det)*dx*dy; // ng/h
               fluxHgIIzdepext2 += HgIIatm*(Pr/det)*dx*dy; // ng/h  
               fluxMMHgzdepext2 += MMHgatm*(Pr/det)*dx*dy; // ng/h 
               fluxSPMzdepext2 += phiSPMatm*pow(10.0,-3.0)*dx*dy; // Kg/h
           }
           else{
               fluxHg0zatmext2 += 0.0; // ng/h
               fluxHg0zdepext2 += 0.0; // ng/h
               fluxHgIIzdepext2 += 0.0; // ng/h
               fluxMMHgzdepext2 += 0.0; // ng/h
               fluxSPMzdepext2 += 0.0; // Kg/h
           }
           
           }
       }
   }
   
       for(j=jext3; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[H][j][k]==Rbot){  
               fluHgIIzsedext3 += MTCIIsw[H][j]*(HgIIpw[H][j][1]-HgII[H][j][k])*dx*dy-HgIIpw[H][j][1]*porsed[H][j][1]*dep[H][j]*dx*dy; // microg/h
               fluMMHgzsedext3 += MTCMMsw[H][j]*(MMHgpw[H][j][1]-MMHg[H][j][k])*dx*dy-MMHgpw[H][j][1]*porsed[H][j][1]*dep[H][j]*dx*dy; // microg/h   
               fluHgIIzburext3 += HgIIpw[H][j][1]*kDIIsed*SWsed[H][j]*dep[H][j]*dx*dy+HgIIpw[H][j][1]*porsed[H][j][1]*dep[H][j]*dx*dy; // microg/h
               fluMMHgzburext3 += MMHgpw[H][j][1]*kDMMsed*SWsed[H][j]*dep[H][j]*dx*dy+MMHgpw[H][j][1]*porsed[H][j][1]*dep[H][j]*dx*dy; // microg/h
           }
           else{
               fluHgIIzsedext3 += 0.0;
               fluMMHgzsedext3 += 0.0;
               fluHgIIzburext3 += 0.0; // microg/h
               fluMMHgzburext3 += 0.0; // microg/h
           } 
            
           if(Rini[H][j][1]>=Rin && Rini[i][j][k]==Rbot){
               fluxHg0zatmext3 += -1.0*MTCwa[H][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[H][j][1])*pow(10.0,3.0)*dx*dy; // ng/h
               fluxHg0zdepext3 += Hggas*(Pr/det)*dx*dy; // ng/h
               fluxHgIIzdepext3 += HgIIatm*(Pr/det)*dx*dy; // ng/h  
               fluxMMHgzdepext3 += MMHgatm*(Pr/det)*dx*dy; // ng/h 
               fluxSPMzdepext3 += phiSPMatm*pow(10.0,-3.0)*dx*dy; // Kg/h
           }
           else{
               fluxHg0zatmext3 += 0.0; // ng/h
               fluxHg0zdepext3 += 0.0; // ng/h
               fluxHgIIzdepext3 += 0.0; // ng/h
               fluxMMHgzdepext3 += 0.0; // ng/h
               fluxSPMzdepext3 += 0.0; // Kg/h
           }
            
           }
       }
   
   TotfluHg0xlev += fluHg0xlev*dt*pow(10,-9.0)*(1.0/PMHg0);
   TotfluHgIIxlev += fluHgIIxlev*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgxlev += fluMMHgxlev*dt*pow(10,-9.0)*(1.0/PMMMHg);
   Totlev += fluTHgxlev*dt*pow(10,-9.0)*(1.0/PMHgII);
   
   TotfluHg0xysci += (fluHg0ysci+fluHg0xsci)*dt*pow(10,-9.0)*(1.0/PMHg0);
   TotfluHgIIxysci += (fluHgIIysci+fluHgIIxsci)*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgxysci += (fluMMHgysci+fluMMHgxsci)*dt*pow(10,-9.0)*(1.0/PMMMHg);
   Totsci += (fluTHgysci+fluTHgxsci)*dt*pow(10,-9.0)*(1.0/PMHgII);
   
   TotfluHgIIzsed += fluHgIIzsed*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzsed += fluMMHgzsed*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzbur += fluHgIIzbur*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzbur += fluMMHgzbur*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzsedext1 += fluHgIIzsedext1*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzsedext1 += fluMMHgzsedext1*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext1 += fluHgIIzburext1*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext1 += fluMMHgzburext1*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzsedext2 += fluHgIIzsedext2*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzsedext2 += fluMMHgzsedext2*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext2 += fluHgIIzburext2*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext2 += fluMMHgzburext2*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzsedext3 += fluHgIIzsedext3*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzsedext3 += fluMMHgzsedext3*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext3 += fluHgIIzburext3*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext3 += fluMMHgzburext3*dt*pow(10,-9.0)*(1.0/PMMMHg);
   
   TotfluHg0zatm += fluxHg0zatm*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHg0zdep += fluxHg0zdep*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHgIIzdep += fluxHgIIzdep*dt*pow(10,-12.0)*(1.0/PMHgII);
   TotfluMMHgzdep += fluxMMHgzdep*dt*pow(10,-12.0)*(1.0/PMMMHg);
   TotfluSPMzdep += fluxSPMzdep*dt;
   TotfluHg0zatmext1 += fluxHg0zatmext1*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHg0zdepext1 += fluxHg0zdepext1*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHgIIzdepext1 += fluxHgIIzdepext1*dt*pow(10,-12.0)*(1.0/PMHgII);
   TotfluMMHgzdepext1 += fluxMMHgzdepext1*dt*pow(10,-12.0)*(1.0/PMMMHg);
   TotfluSPMzdepext1 += fluxSPMzdepext1*dt;
   TotfluHg0zatmext2 += fluxHg0zatmext2*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHg0zdepext2 += fluxHg0zdepext2*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHgIIzdepext2 += fluxHgIIzdepext2*dt*pow(10,-12.0)*(1.0/PMHgII);
   TotfluMMHgzdepext2 += fluxMMHgzdepext2*dt*pow(10,-12.0)*(1.0/PMMMHg);
   TotfluSPMzdepext2 += fluxSPMzdepext2*dt;
   TotfluHg0zatmext3 += fluxHg0zatmext3*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHg0zdepext3 += fluxHg0zdepext3*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHgIIzdepext3 += fluxHgIIzdepext3*dt*pow(10,-12.0)*(1.0/PMHgII);
   TotfluMMHgzdepext3 += fluxMMHgzdepext3*dt*pow(10,-12.0)*(1.0/PMMMHg);
   TotfluSPMzdepext3 += fluxSPMzdepext3*dt;
   
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
 }
 
 //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Queste variabili dipendono dalla forma del bacino%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
 
   TotHgIIsed=TotfluHgIIzsed-TotfluHgIIzsedext1-TotfluHgIIzsedext2-TotfluHgIIzsedext3;
   TotMMHgsed=TotfluMMHgzsed-TotfluMMHgzsedext1-TotfluMMHgzsedext2-TotfluMMHgzsedext3;
   TotHgsed=TotHgIIsed+TotMMHgsed;
   TotHgIIbur=TotfluHgIIzbur-TotfluHgIIzburext1-TotfluHgIIzburext2-TotfluHgIIzburext3;
   TotMMHgbur=TotfluMMHgzbur-TotfluMMHgzburext1-TotfluMMHgzburext2-TotfluMMHgzburext3;
   TotHgbur=TotHgIIbur+TotMMHgbur;
   TotfluHg0atm=TotfluHg0zatm-TotfluHg0zatmext1-TotfluHg0zatmext2-TotfluHg0zatmext3;
   TotfluHg0dep=TotfluHg0zdep-TotfluHg0zdepext1-TotfluHg0zdepext2-TotfluHg0zdepext3;
   TotfluHgIIdep=TotfluHgIIzdep-TotfluHgIIzdepext1-TotfluHgIIzdepext2-TotfluHgIIzdepext3;
   TotfluMMHgdep=TotfluMMHgzdep-TotfluMMHgzdepext1-TotfluMMHgzdepext2-TotfluMMHgzdepext3;
   TotfluHgdep=TotfluHg0dep+TotfluHgIIdep+TotfluMMHgdep;
   TotfluSPMdep=(TotfluSPMzdep-TotfluSPMzdepext1-TotfluSPMzdepext2-TotfluSPMzdepext3)*pow(10.0,-3.0);
   
 //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   
   
   fprintf(fu,"  Hg0lev        HgIIlev        MMHglev         Totlev         Hg0sci         HgIIsci         MMHgsci         Totsci \n");
   fprintf(fu, "%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", TotfluHg0xlev, TotfluHgIIxlev, TotfluMMHgxlev, Totlev, TotfluHg0xysci, TotfluHgIIxysci, TotfluMMHgxysci,Totsci);
   fprintf(fu,"  TotHgIIsed       TotMMHgsed       TotHgsed       TotHgIIbur       TotMMHgbur       TotHgbur \n");
   fprintf(fu, "%f\t%f\t%f\t%f\t%f\t%f\n", TotHgIIsed, TotMMHgsed, TotHgsed, TotHgIIbur, TotMMHgbur, TotHgbur);
   fprintf(fu,"  TotSIIDOM      TotSMMDOM      TotHgIISPM      TotMMHgSPM \n");
   fprintf(fu, "%f\t%f\t%f\t%f\n", TotSIIDOM, TotSMMDOM, TotSIISPM, TotSMMSPM);
   fprintf(fu,"  TotfluHg0atm  TotfluHg0dep   TotfluHgIIdep  TotfluMMHgdep   TotfluHgdep   TotfluSPMdep\n");
   fprintf(fu, "%f\t%f\t%f\t%f\t%f\t%f\n", TotfluHg0atm, TotfluHg0dep, TotfluHgIIdep,TotfluMMHgdep,TotfluHgdep,TotfluSPMdep);
   fprintf(fRelease, "%i\t%f\t%f\t%f\n", n+2004, TotHgIIsed, TotMMHgsed, TotHgsed);
   fprintf(fOutflow, "%i\t%f\t%f\t%f\n", n+2004, Totlev, Totsci, Totlev+Totsci);
   fprintf(fEvasion, "%i\t%f\t%f\t%f\n", n+2004, TotfluHg0atm, TotfluHgdep, TotfluHg0atm-TotfluHgdep);
   fprintf(fRecycled, "%i\t%f\t%f\t%f\n", n+2004, TotHgsed-Totlev-Totsci-TotfluHg0atm+TotfluHgdep, TotHgbur, TotSIISPM+TotSMMSPM);
   
   if(n>T-1 && n<T1){
     for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
           for(k=1; k<=K; k++){
             
             if(Rini[i][j][k]==Rbot){
             PHgIIsptmean+=PHgIItmean[i][j][k]/SUR;
             PMMHgsptmean+=PMMHgtmean[i][j][k]/SUR;                     
             }
             else{
             PHgIIsptmean+=0.0;
             PMMHgsptmean+=0.0;  
             }   
 
          }
        
          if(Rini[i][j][1]>=Rin){
             ZHgIIsptmean+=(ZHgIItmean[i][j]/SUR);
             ZMMHgsptmean+=(ZMMHgtmean[i][j]/SUR);                   
             FiHgIIsptmean+=(FiHgIItmean[i][j]/SUR); 
             FiMMHgsptmean+=(FiMMHgtmean[i][j]/SUR); 
          }
          else{
             ZHgIIsptmean+=0.0;
             ZMMHgsptmean+=0.0;  
             FiHgIIsptmean+=0.0;
             FiMMHgsptmean+=0.0;
          } 
           
        } 
     } 
  } 
  
  if(n>N-T && n<=N){
     for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
           for(k=1; k<=K; k++){
             
             if(Rini[i][j][k]==Rbot){
             PHgIIsptmean2+=PHgIItmean2[i][j][k]/SUR;
             PMMHgsptmean2+=PMMHgtmean2[i][j][k]/SUR;                     
             }
             else{
             PHgIIsptmean2+=0.0;
             PMMHgsptmean2+=0.0;  
             }   
 
          }
        
          if(Rini[i][j][1]>=Rin){
             ZHgIIsptmean2+=(ZHgIItmean2[i][j]/SUR);
             ZMMHgsptmean2+=(ZMMHgtmean2[i][j]/SUR);                   
             FiHgIIsptmean2+=(FiHgIItmean2[i][j]/SUR); 
             FiMMHgsptmean2+=(FiMMHgtmean2[i][j]/SUR); 
          }
          else{
             ZHgIIsptmean2+=0.0;
             ZMMHgsptmean2+=0.0;  
             FiHgIIsptmean2+=0.0;
             FiMMHgsptmean2+=0.0;
          } 
           
        } 
     } 
  }
  
 }  
   
   fprintf(fFisptmean,"HgII phyto (mg/Kg) MMHg phyto (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", PHgIIsptmean, PMMHgsptmean);
   fprintf(fFisptmean,"HgII Amphipode (mg/Kg) MMHg Amphipode (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZHgIIsptmean, ZMMHgsptmean);
   fprintf(fFisptmean,"HgII Mullus (mg/Kg) MMHg Mullus (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", FiHgIIsptmean, FiMMHgsptmean);
   fprintf(fFisptmean,"HgII phyto (mg/Kg) MMHg phyto (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", PHgIIsptmean2, PMMHgsptmean2);
   fprintf(fFisptmean,"HgII Amphipode (mg/Kg) MMHg Amphipode (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZHgIIsptmean2, ZMMHgsptmean2);
   fprintf(fFisptmean,"HgII Mullus (mg/Kg) MMHg Mullus (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", FiHgIIsptmean2, FiMMHgsptmean2);
  
   for(i=1; i<=I; i++){
       for(j=1; j<=J; j++){
           fprintf(fZtmean,"%f\t%f\t%f\t%f\n", (i-1)*dx, (j-1)*dy, ZHgIItmean[i][j], ZMMHgtmean[i][j]);            
           fprintf(fFitmean,"%f\t%f\t%f\t%f\n", (i-1)*dx, (j-1)*dy, FiHgIItmean[i][j], FiMMHgtmean[i][j]);
       }
   }
   
   fclose(fb1);
   fclose(fct);
   fclose(fR);
   fclose(fI);
   fclose(fHg0);
   fclose(fHgII);
   fclose(fMMHg);
   fclose(fDHg);
   fclose(fTHg);
   //fclose(fSPM);
   fclose(fHgIIpw);
   fclose(fMMHgpw);
   fclose(fHgIIfluxsed);
   fclose(fMMHgfluxsed);
   fclose(fHg0fluxatm);
   fclose(fHg0fluxdep);
   fclose(fHgIIfluxdep);
   fclose(fMMHgfluxdep);
   fclose(fu);
   fclose(fRelease);
   fclose(fOutflow);
   fclose(fEvasion);
   fclose(fRecycled);
   fclose(fP);
   fclose(fZ);
   fclose(fFi);
   fclose(fZtmean);
   fclose(fFitmean);
   fclose(fFisptmean);
   fclose(fRin1);
   fclose(fSPMin1);
   fclose(fSPOMin1);
   fclose(fRin2);
   fclose(fSPMin2);
   fclose(fSPOMin2);
   fclose(fRin3);
   fclose(fSPMin3);
   fclose(fSPOMin3);
   fclose(fRin4);
   fclose(fSPMin4);
   fclose(fSPOMin4);
   fclose(fRin5);
   fclose(fSPMin5);
   fclose(fSPOMin5);
   fclose(fRin6);
   fclose(fSPMin6);
   fclose(fSPOMin6);
   fclose(fTHgsedin);
   fclose(fTHgsedin2);
   fclose(fTHgsedin3);
   fclose(fTHgsedin4);
   fclose(fTHgsedin5);
   fclose(fTHgsedin6);
   fclose(fTHgsedin7);
   fclose(fTHgsedin8);
   fclose(fTHgsedin9);
   fclose(fTHgsedin10);
   fclose(fTHgsed);
   fclose(ftotdep);
   fclose(fSWsed);
   fclose(fTOCsed);
   fclose(fporsed);
   fclose(fporsed2);
   fclose(fporsed3);
   fclose(fporsed4);
   fclose(fporsed5);
   fclose(fporsed6);
   fclose(fporsed7);
   fclose(fporsed8);
   fclose(fporsed9);
   fclose(fporsed10);
   fclose(fIin);
   fclose(fTatm);
   fclose(fPrec);
   fclose(fHgIIatm);
   fclose(fHggas);
   fclose(fv5);
   fclose(fv10);
   fclose(fv20);
   fclose(fv30);
   fclose(fero);
   fclose(fero2);
}
