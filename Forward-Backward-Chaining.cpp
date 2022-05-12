#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <unordered_map>
#include <iostream>
#include <cstring>

using namespace std;


class Backward{
    private:
        unordered_map<int, string> clvarlt = {  {1,"SB"},{6,"SB"},{7,"DZ"},{11,"SB"},{12,"DZ"},
                                                {16,"BI"},{17,"FA"},{18,"AR"},{21,"PC"},{22,"EI"},
                                                {26,"PC"},{27,"EI"},{31,"BI"},{32,"FA"},{33,"AR"},
                                                {36,"HM"},{37,"NV"},{41,"HM"},{42,"NV"},{43,"AM"},
                                                {46,"MD"},{47,"FE"},{51,"MD"},{52,"FE"},{53,"PB"},
                                                {56,"MD"},{57,"FE"},{58,"PB"},{61,"BI"},{62,"FA"},
                                                {63,"NA"},{66,"BI"},{67,"FA"},{68,"NA"},{71,"ST"},
                                                {72,"SR"},{76,"ST"},{77,"SR"},{78,"SL"},{81,"ID"},
                                                {82,"HC"},{86,"ID"},{87,"HC"},{91,"VS"},{92,"VO"},
                                                {96,"VS"},{97,"VO"},{101,"SA"},{102,"FN"},{106,"SA"},
                                                {107,"FN"},{111,"DI"},{112,"CP"},{116,"DI"},{117,"CP"},
                                                {118,"HP"},{121,"HF"},{122,"TD"},{126,"HF"},{127,"TD"},
                                                {131,"DI"},{132,"CP"},{133,"HP"},{136,"VI"},{137,"SF"},
                                                {141,"VI"},{142,"SF"},{143,"RV"},{146,"VI"},{147,"SF"},
                                                {148,"RV"},{149,"HB"}};
        char conclt[31][3]; // length of conclusion 3 is length of variable name
        char varlt[22][3]; // length of variable list
        char varble[3];
        char BI[4], SA[4], PC[4], HM[4], MD[4], ST[4], ID[4], VS[4], DI[4], HF[4], VI[4] ;
        char SB[4], DZ[4], FA[4], AR[4], NV[4], EI[4], AM[4], FE[4], PB[4], NA[4], SR[4], SL[4], HC[4], VO[4], FN[4], CP[4], HP[4], TD[4], SF[4], RV[4], HB[4];

        char buff[128];
        int instlt[22]; // equal to variable list
        int statsk[31];
        int clausk[31];
        int i, k, s, sn, sp, f;

     public:
        char DE[4];
        Backward(){
            setup_data_structures();
        }

        void setup_data_structures()
        {
            sp = 31;
            for (i=1; i<31; i++)
            {
                statsk[i]=0;
                clausk[i]=0;
            }

            for (i=1; i < 22; i++)
            {
                instlt[i] = 0;
                strcpy(varlt[i],"");
            }

            for (i=1; i<31; i++)
            {
                strcpy(conclt[i],"");

            }
            // CONCLUSION LIST
            strcpy(conclt[1], "DE");
            strcpy(conclt[2], "BI");
            strcpy(conclt[3], "SA");
            strcpy(conclt[4], "PC");
            strcpy(conclt[5], "DE");
            strcpy(conclt[6], "DE");
            strcpy(conclt[7], "HM");
            strcpy(conclt[8], "DE");
            strcpy(conclt[9], "MD");
            strcpy(conclt[10], "DE");
            strcpy(conclt[11], "DE");
            strcpy(conclt[12], "DE");
            strcpy(conclt[13], "DE");
            strcpy(conclt[14], "ST");
            strcpy(conclt[15], "DE");
            strcpy(conclt[16], "ID");
            strcpy(conclt[17], "DE");
            strcpy(conclt[18], "VS");
            strcpy(conclt[19], "DE");
            strcpy(conclt[20], "DE");
            strcpy(conclt[21], "DE");
            strcpy(conclt[22], "DI");
            strcpy(conclt[23], "DE");
            strcpy(conclt[24], "HF");
            strcpy(conclt[25], "DE");
            strcpy(conclt[26], "DE");
            strcpy(conclt[27], "VI");
            strcpy(conclt[28], "DE");
            strcpy(conclt[29], "DE");
            strcpy(conclt[30], "DE");
            //  VARIABLE LIST
            strcpy(varlt[1], "SB");
            strcpy(varlt[2], "DZ");
            strcpy(varlt[3], "FA");
            strcpy(varlt[4], "AR");
            strcpy(varlt[5], "NV");
            strcpy(varlt[6], "EI");
            strcpy(varlt[7], "AM");
            strcpy(varlt[8], "FE");
            strcpy(varlt[9], "PB");
            strcpy(varlt[10], "NA");
            strcpy(varlt[11], "SR");
            strcpy(varlt[12], "SL");
            strcpy(varlt[13], "HC");
            strcpy(varlt[14], "VO");
            strcpy(varlt[15], "FN");
            strcpy(varlt[16], "CP");
            strcpy(varlt[17], "HP");
            strcpy(varlt[18], "TD");
            strcpy(varlt[19], "SF");
            strcpy(varlt[20], "RV");
            strcpy(varlt[21], "HB");


        }

        void diagnose()
        {   printf("\n \nSTART THE PROCESS TO DIAGNOSE. \nHIT RETURN TO CONTINUE");
            gets(buff);
            printf("*** CONCLUSION LIST ***\n");
            for (i=1; i<31; i++) printf("CONCLUSION %d %s\n", i,conclt[i]);
            printf("HIT RETURN TO CONTINUE");
            gets(buff);
            printf("\n*** VARIABLE LIST *\n");

            for(i=1; i<22; i++) printf("VARIABLE %d %s\n", i, varlt[i]);

            printf("HIT RETURN KEY TO CONTINUE");
            gets(buff);

            printf("*** CLAUSE VARIABLE LIST ***\n");
            for(i=1; i<31; i++)
            {
                printf("** CLAUSE %d\n", i);
                for(int j=1; j<6; j++)
                { k = 5 * (i-1) + j;
                    cout <<"VARIABLE "<< j << " "<<  find_var_in_clvarlt(clvarlt, k) << endl;
                }
                if (i==30)
                { printf("HIT RETURN KEY TO CONTINUE"); gets(buff); }
            }

            strcpy(DE,""); strcpy(BI,""); strcpy(SA,""); strcpy(PC,""); strcpy(HM,"");strcpy(MD,"");
            strcpy(ST,""); strcpy(ID,""); strcpy(VS,""); strcpy(DI,""); strcpy(HF,"");
            strcpy(VI,""); strcpy(SB,""); strcpy(DZ,""); strcpy(FA,""); strcpy(AR,"");
            strcpy(NV,""); strcpy(EI,""); strcpy(AM,""); strcpy(FE,""); strcpy(PB,"");
            strcpy(NA,""); strcpy(SR,""); strcpy(SL,""); strcpy(HC,""); strcpy(VO,""); strcpy(FN,""); strcpy(CP,"");
            strcpy(HP,""); strcpy(TD,""); strcpy(SF,""); strcpy(RV,""); strcpy(HB,"");

            printf("** ENTER CONCLUSION ? "); gets(varble);
            this->process_stack();
            printf("HIT RETURN TO CONTINUE");
            gets(buff);
        }


        void process_stack()
        {
            this->f=1;
            determine_member_concl_list();
            if (sn != 0){
                do{
                    push_on_stack();
                    sub_process_stack1();
                    sn = statsk[sp];
                    s = 0;
                    check_if_part();
                    move_stack();
                } while((s != 1) && (sn !=0));
            sub_process_stack2();
            }

        }

        void sub_process_stack1()
        {
            do
            {
                int i= (statsk[sp] -1) *5 + clausk[sp];
                strcpy(varble, (find_var_in_clvarlt(clvarlt, i)).c_str());
                if(strcmp(varble, "") != 0)
                {
                    f = 1;
                    determine_member_concl_list();
                    if(sn != 0)
                    process_stack();
                    instantiate();
                    clausk[sp] = clausk[sp] + 1;
                }
            } while(strcmp(varble, "") != 0);
        }

        void sub_process_stack2(){
            if(sn != 0)
            {
                print_then_part();
                sp=sp+1;
                if(sp >= 31)
                {
                    printf("*** SUCCESS\n");
                    return;
                }
                else
                {
                    clausk[sp] = clausk[sp]+1;
                    sub_process_stack1();
                    sn = statsk[sp];
                    s = 0;
                    check_if_part();
                    move_stack();
                    while((s != 1) && (sn !=0))
                    {
                        push_on_stack();
                        this->sub_process_stack1();
                        sn = statsk[sp];
                        s = 0;
                        check_if_part();
                        check_if_part();
                    }
                    sub_process_stack2();
                }
            }
        }

    void move_stack()
    {
        if( s != 1)
        {
            i = statsk[sp];
            strcpy(varble, conclt[i]);
            f = statsk[sp] + 1;
            determine_member_concl_list();
            sp = sp+1;
        }
    }


    void check_if_part()
    {   s = 0;
        switch (sn) //implement IF-PART
        {
            case 1: if(strcmp(SB, "NO") == 0) s = 1;
                    break;
            case 2: if ((strcmp(SB, "YES") == 0) && (strcmp(DZ, "YES") == 0)) s = 1;
                    break;
            case 3: if((strcmp(SB, "YES") == 0) && (strcmp(DZ, "NO") == 0)) s =1;
                    break;
            case 4: if ((strcmp(BI, "YES") == 0) && (strcmp(FA, "YES") == 0) && (strcmp(AR, "YES") == 0))  s = 1;
                    break;
            case 5: if ((strcmp(PC, "YES") == 0) && (strcmp(EI, "YES") == 0)) s = 1;
                    break;
            case 6: if ((strcmp(PC, "YES") == 0) && (strcmp(EI, "NO") == 0)) s = 1;
                    break;
            case 7: if ((strcmp(BI, "YES") == 0) && (strcmp(FA, "YES") == 0) && (strcmp(AR, "NO") == 0)) s = 1;
                    break;
            case 8: if ((strcmp(HM, "YES") == 0) && (strcmp(NV, "YES") == 0)) s = 1;
                    break;
            case 9: if ((strcmp(HM, "YES") == 0) && (strcmp(NV, "NO") == 0) && (strcmp(AM, "YES") == 0)) s = 1;
                    break;
            case 10: if ((strcmp(MD, "YES") == 0) && (strcmp(FE, "YES") == 0)) s = 1;
                    break;
            case 11: if ((strcmp(MD, "YES") == 0) && (strcmp(FE, "NO") == 0) && (strcmp(PB, "YES") == 0)) s = 1;
                    break;
            case 12: if ((strcmp(MD, "YES") == 0) && (strcmp(FE, "NO") == 0) && (strcmp(PB, "NO") == 0)) s = 1;
                    break;
            case 13: if ((strcmp(BI, "YES") == 0) && (strcmp(FA, "NO") == 0) && (strcmp(NA, "YES") == 0)) s = 1;
                    break;
            case 14: if ((strcmp(BI, "YES") == 0) && (strcmp(FA, "NO") == 0) && (strcmp(NA, "NO") == 0)) s = 1;
                    break;
            case 15: if ((strcmp(ST, "YES") == 0) && (strcmp(SR, "YES") == 0)) s = 1;
                    break;
            case 16: if ((strcmp(ST, "YES") == 0) && (strcmp(SR, "NO") == 0) && (strcmp(SL, "YES") == 0))s =1;
                    break;
            case 17: if ((strcmp(ID, "YES") == 0) && (strcmp(HC, "YES") == 0)) s = 1;
                    break;
            case 18: if ((strcmp(ID, "YES") == 0) && (strcmp(HC, "NO") == 0)) s = 1;
                    break;
            case 19: if ((strcmp(VS, "YES") == 0) && (strcmp(VO, "YES") == 0)) s = 1;
                    break;
            case 20: if ((strcmp(VS, "YES") == 0) && (strcmp(VO, "NO") == 0)) s = 1;
                    break;
            case 21: if ((strcmp(SA, "YES") == 0) && (strcmp(FN, "YES") == 0)) s = 1;
                    break;
            case 22: if ((strcmp(SA, "YES") == 0) && (strcmp(FN, "NO") == 0)) s = 1;
                    break;
            case 23: if ((strcmp(DI, "YES") == 0) && (strcmp(CP, "YES") == 0)) s = 1;
                    break;
            case 24: if ((strcmp(DI, "YES") == 0) && (strcmp(CP, "NO") == 0) && (strcmp(HP, "YES") == 0)) s = 1;
                    break;
            case 25: if ((strcmp(HF, "YES") == 0) && (strcmp(TD, "YES") == 0)) s = 1;
                    break;
            case 26: if ((strcmp(HF, "YES") == 0) && (strcmp(TD, "NO") == 0)) s = 1;
                    break;
            case 27: if ((strcmp(DI, "YES") == 0) && (strcmp(CP, "NO") == 0) && (strcmp(HP, "NO") == 0)) s = 1;
                    break;
            case 28: if ((strcmp(VI, "YES") == 0) && (strcmp(SF, "YES") == 0)) s = 1;
                    break;
            case 29: if ((strcmp(VI, "YES") == 0) && (strcmp(SF, "NO") == 0) && (strcmp(RV, "YES") == 0)) s = 1;
                    break;
            case 30: if ((strcmp(VI, "YES") == 0) && (strcmp(SF, "NO") == 0) && (strcmp(RV, "NO") == 0) && (strcmp(HB, "YES") == 0)) s = 1;
                    break;
        }
    }

    void print_then_part()
    {
        switch (sn)
        {
            case 1: strcpy(DE, "NO");
                    printf("DE=NO\n");
                    break;
            case 2: strcpy(BI, "YES");
                    printf("BI=YES\n");
                    break;
            case 3: strcpy(SA, "YES");
                    printf("SA=YES\n");
                    break;
            case 4: strcpy(PC, "YES");
                    printf("PC=YES\n");
                    break;
            case 5: strcpy(DE, "CL");
                    printf("DE=Cardiomegaly");
                    break;
            case 6: strcpy(DE, "AR");
                    printf("DE=Arrhythmias\n");
                    break;
            case 7: strcpy(HM, "YES");
                    printf("HM=YES\n");
                    break;
            case 8: strcpy(DE, "MM");
                    printf("DE=Mitral Valve Disease");
                    break;
            case 9: strcpy(MD, "YES");
                    printf("MD=YES");
                    break;
            case 10: strcpy(DE, "YT");
                    printf("DE=Myocarditis\n");
                    break;
            case 11: strcpy(DE, "PT");
                    printf("DE=Pericarditits");
                    break;
            case 12: strcpy(DE, "EC");
                    printf("DE=Endocarditis\n");
                    break;
            case 13: strcpy(DE, ":CA");
                    printf("DE=Coronary Arteryn");
                    break;
            case 14: strcpy(ST, "YES");
                    printf("ST=YES\n");
                    break;
            case 15: strcpy(DE, "CY");
                    printf("DE=Cardiomyopathy\n");
                    break;
            case 16: strcpy(ID, "YES");
                    printf("ID=YES\n");
                    break;
            case 17: strcpy(DE, "CM");
                    printf("DE=Coronary Microvascular Disease");
                    break;
            case 18: strcpy(VS, "YES");
                    printf("VS=YES\n");
                    break;
            case 19: strcpy(DE, "OD");
                    printf("DE = Obstructive Coronary Artery Disease\n");
                    break;
            case 20: strcpy(DE, "ND");
                    printf("DE = Non-obstructive Coronary Artery Disease\n");
                    break;
            case 21: strcpy(DE, "AO");
                    printf("DE = Aorta\n");
                    break;
            case 22: strcpy(DI, "YES");
                    printf("DI= YES\n");
                    break;
            case 23: strcpy(DE, "CN");
                    printf("DE = Congenital");
                    break;
            case 24: strcpy(HF, "YES");
                    printf("HF=YES\n");
                    break;
            case 25: strcpy(DE, "HF");
                    printf("DE = Heart Failure\n");
                    break;
            case 26: strcpy(DE, "HH");
                    printf("DE = Hypertensive Heart Disease\n");
                    break;
            case 27: strcpy(VI, "YES");
                    printf("VI=YES\n");
                    break;
            case 28: strcpy(DE, "RD");
                    printf("DE = Rheumatic Heart Disease\n");
                    break;
            case 29: strcpy(DE, "CU");
                    printf("DE = Congenital Rubella");
                    break;
            case 30: strcpy(DE, "AM");
                    printf("DE = Acute Myocarditis\n");
                    break;
        }
    }


    void determine_member_concl_list()
    {
        sn = 0;
        i = f; /* member of conclusion list to be searched is f */
        while((strcmp(varble, conclt[i]) != 0) && (i<31)) i=i+1;/* test for membership */
        if (strcmp(varble, conclt[i]) == 0) sn = i;  /* a member */
    }

    void push_on_stack()
    {
        sp=sp-1;
        statsk[sp] = sn;
        clausk[sp] = 1;
    }

    void instantiate()
    {
        i=1;
        while((strcmp(varble, varlt[i]) != 0) && (i<22)) i=i+1;/* find variable in the list */
        if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1))
                /*found variable and not already instantiated */
        {
            instlt[i]=1; /*mark instantiated */
            switch (i)
            {
                case 1: printf("INPUT YES OR NO FOR short breath (SB)? ");
                        gets(SB);
                        break;
                case 2: printf("INPUT YES OR NO FOR dizziness (DZ)? ");
                        gets(DZ);
                        break;
                case 3: printf("INPUT YES OR NO FOR fatigue (FA)? ");
                        gets(FA);
                        break;
                case 4: printf("INPUT YES OR NO FOR abnormal_heart_rhythm (AR)? ");
                        gets(AR);
                        break;
                case 5: printf("INPUT YES OR NO FOR enlarged_neck_vien (NV)? ");
                        gets(NV);
                        break;
                case 6: printf("INPUT YES OR NO FOR excess_iron_in_body	(EI)? ");
                        gets(EI);
                        break;
                case 7: printf("INPUT YES OR NO FOR aching_joints_muscles (AM)? ");
                        gets(AM);
                        break;
                case 8: printf("INPUT YES OR NO FOR fever (FE)? ");
                        gets(FE);
                        break;
                case 9: printf("INPUT YES OR NO FOR pain_behind_brestbone (PB)? ");
                        gets(PB);
                        break;
                case 10: printf("INPUT YES OR NO FOR nausea (NA)? ");
                        gets(NA);
                        break;
                case 11: printf("INPUT YES OR NO FOR swell_result (SR)? ");
                        gets(SR);
                        break;
                case 12: printf("INPUT YES OR NO FOR sedentary_lifestyle (SL)? ");
                        gets(SL);
                        break;
                case 13: printf("INPUT YES OR NO FOR high_cholesterol (HC)? ");
                        gets(HC);
                        break;
                case 14: printf("INPUT YES OR NO FOR vascular_obstruction (VO)? ");
                        gets(VO);
                        break;
                case 15: printf("INPUT YES OR NO FOR fainting (FN)? ");
                        gets(FN);
                        break;
                case 16: printf("INPUT YES OR NO FOR chest_pain	(CP)? ");
                        gets(CP);
                        break;
                case 17: printf("INPUT YES OR NO FOR high_blood_pressure (HP) ");
                        gets(HP);
                        break;
                case 18: printf("INPUT YES OR NO FOR thyroid_disease (TD)? ");
                        gets(TD);
                        break;
                case 19: printf("INPUT YES OR NO FOR scarlet_fever (SF)? ");
                        gets(SF);
                        break;
                case 20: printf("INPUT YES OR NO FOR rubella_virus (RV)? ");
                        gets(RV);
                        break;
                case 21: printf("INPUT YES OR NO FOR human_parvovirus_b19 (HB)? ");
                        gets(HB);
                        break;
            }
        }
    }


    string find_var_in_clvarlt(unordered_map<int, string> clvarlt,int key)
    {
        unordered_map<int, string>::const_iterator got = clvarlt.find(key);
        if ( got == clvarlt.end())
        return "";
        else
        {
            return clvarlt.at(key);
        }
    }

};

class Forward{
    private:
    int flag;
    char cndvar[36][3];
    char varlt[36][3];
    unordered_map<int, string> clvarlt =  { {1,"HD"},{2,"AR"},{3,"CL"},{4,"MM"},{6,"AT"},{7,"HV"},
                                            {8,"RO"},{11,"AT"},{12,"HV"},{13,"RO"},{16,"AT"},
                                            {17,"HV"},{18,"RO"},{21,"HD"},{22,"CA"},{23,"ND"},
                                            {24,"CM"}, {25,"OD"},{26,"CT"},{27,"HC"},{31,"CT"},
                                            {32,"HC"},{36,"AC"},{37,"EM"},{41,"AC"},{42,"EM"},
                                            {46,"HD"},{47,"CY"},{48,"YT"},{49,"PT"},{50,"EC"},
                                            {51,"RT"},{52,"SE"},{56,"RT"},{57,"SE"},{58,"EM"},
                                            {61,"HD"},{62,"AO"},{63,"RD"},{64,"CU"},{65,"AM"},
                                            {66,"OT"},{67,"SE"},{71,"OT"},{72,"SE"},{76,"AG"},
                                            {77,"OR"},{81,"AG"},{82,"OR"},{86,"HD"},{87,"CN"},
                                            {88,"HF"},{89,"HH"},{91,"GT"},{92,"SE"},{96,"GT"},
                                            {97,"SE"},{98,"GD"},{99,"GC"},{101,"GT"},{102,"SE"},
                                            {103,"GD"},{104,"GC"},{106,"GT"},{107,"SE"},{108,"GD"},
                                            {111,"GG"} };
    char c[3], vp[3], /* condition variable */  v[3]; /*variable */


    char    HD[4], AR[4], AT[4], HV[4], RO[4], CA[4], CT[4], HC[4], AC[4], EM[4], CY[4],  RT[4],
            SE[4], AO[4], OT[4], AG[4], OR[4], CN[4], GT[4], GD[4], GC[4], GG[4], TR [4], CL[4],
            ND[4], CM[4], OD[4], YT[4], PT[4], EC[4], RD[4], CU[4], AM[4], HF[4], HH[4], MM[4];


    int instlt[36];         /* instantiated list*/
    int f, i, j, k, s, fp   /* front pointer */;
    int  bp  /* back pointer */, sn; /* statement number */
    int cn;  /* clause number */
    char buff[128];

    public:

    Forward()
    {
        setup_data_structure();

    }
    void setup_data_structure()
    {
        fp=1;
        bp=1;
        for (i=1;i < 36; i++)
        {
            strcpy(cndvar[i], "");
            strcpy(varlt[i], "");
            instlt[i]= 0;
        }

     // DONE DECLARE ALL VARIABLE LIST
        strcpy(varlt[1], "HD");
        strcpy(varlt[2], "AR");
        strcpy(varlt[3], "AT");
        strcpy(varlt[4], "HV");
        strcpy(varlt[5], "RO");
        strcpy(varlt[6], "CA");
        strcpy(varlt[7], "CT");
        strcpy(varlt[8], "HC");
        strcpy(varlt[9], "AC");
        strcpy(varlt[10], "EM");
        strcpy(varlt[11], "CY");
        strcpy(varlt[12], "RT");
        strcpy(varlt[13], "SE");
        strcpy(varlt[14], "AO");
        strcpy(varlt[15], "OT");
        strcpy(varlt[16], "AG");
        strcpy(varlt[17], "OR");
        strcpy(varlt[18], "CN");
        strcpy(varlt[19], "GT");
        strcpy(varlt[20], "GD");
        strcpy(varlt[21], "GC");
        strcpy(varlt[22], "GG");
        strcpy(varlt[23], "CL");
        strcpy(varlt[24], "ND");
        strcpy(varlt[25], "CM");
        strcpy(varlt[26], "OD");
        strcpy(varlt[27], "YT");
        strcpy(varlt[28], "PT");
        strcpy(varlt[29], "EC");
        strcpy(varlt[30], "RD");
        strcpy(varlt[31], "CU");
        strcpy(varlt[32], "AM");
        strcpy(varlt[33], "HF");
        strcpy(varlt[34], "HH");
        strcpy(varlt[35], "MM");
    }

    void recommend_treatment()
    {
        printf("START THE PROCESS TO FIND THE TREATMENT. \n HIT RETURN TO CONTINUE");
        gets(buff);

        printf("*** VARIABLE LIST ***\n");
        for (i=1;i < 36; i++) printf("ENTER VARIABLE   %d   %s\n", i, varlt[i]);
        printf("HIT RETURN TO CONTINUE");
        gets(buff);

        printf("\n*** CLAUSE-VARIABLE LIST ***\n");
        for (i = 1; i < 24; i++)
        {
            printf("** CLAUSE %d\n", i);
            for (j = 1; j < 6; j++)
            {
                k = 5 * (i - 1) + j;
                cout <<"VARIABLE "<< j << " "<<  find_var_in_clvarlt(clvarlt, k) << endl;
            }

            if (i==23)
            {
                printf("HIT RETURN TO CONTINUE");
                gets(buff);
            }
        }
        printf("\nPROCESSING TO GIVE THE TREATMENT \n");

        strcpy(cndvar[bp], "HD");
        bp = bp + 1;
        sn = 1; cn = 1;
        f=1;
        find_treatment();
        return;
    }

    void find_treatment()
    {
        search();
        cn=1;
        if (sn != 0)
        {
            i = 5 * (sn-1) + cn;
            strcpy(v, (find_var_in_clvarlt(clvarlt, i)).c_str());
            while (strcmp(v, "") && i < (5 * (sn-1) + 6))
            {

                check_instantiation();/* check instantiation of this clause */
                cn = cn+1;
                i = 5 * (sn-1) + cn; /* check next clause */
                strcpy(v, (find_var_in_clvarlt(clvarlt, i)).c_str());
            }
            s = 0;
            check_if_part();
            if (s != 1)
            {
                f = sn + 1;
                find_treatment();
            }
            put_var_into_ccls_queue();
            f = sn + 1;
            find_treatment();
        }
        fp=fp+1;
        if (fp < bp)
        {
            f = 1;
            find_treatment();
        }
        return exit(EXIT_SUCCESS);
    }

    void check_if_part(){
        switch(sn)
        {
            case 1: if (strcmp(HD, "YES") == 0 && (strcmp(AR, "YES") == 0 || strcmp(CL, "YES") == 0 || strcmp(MM, "YES") == 0)) s=1;
                break;
            case 2: if (strcmp(AT, "YES") == 0 && strcmp(HV, "NO") == 0 && strcmp(RO, "YES") == 0) s=1;
                break;
            case 3: if (strcmp(AT, "YES") == 0 && strcmp(HV, "YES") == 0 && strcmp(RO, "YES") == 0) s=1;
                break;
            case 4: if (strcmp(AT, "YES") == 0 && strcmp(HV, "YES") == 0 && strcmp(RO, "NO") == 0) s=1;
                break;
            case 5: if (strcmp(HD, "YES") == 0 && (strcmp(CA, "YES") == 0 || strcmp(ND, "YES") == 0 || strcmp(CM, "YES") == 0 || strcmp(OD, "YES") == 0)) s=1;
                break;
            case 6: if (strcmp(CT, "YES") == 0 && strcmp(HC, "YES") == 0) s=1;
                break;
            case 7: if (strcmp(CT, "YES") == 0 && strcmp(HC, "NO") == 0) s=1;
                break;
            case 8: if ((strcmp(AC, "YES") == 0) && (strcmp(EM, "YES")) == 0) s=1;
                break;
            case 9: if ((strcmp(AC, "YES") == 0) && (strcmp(EM, "NO")) == 0) s=1;
                break;
            case 10: if (strcmp(HD, "YES") == 0 && (strcmp(CY, "YES") == 0 || strcmp(YT, "YES") == 0 || strcmp(PT, "YES") == 0 || strcmp(EC, "YES") == 0)) s=1;
                break;
            case 11: if ((strcmp(CT, "YES") == 0) && (strcmp(SE, "NO")) == 0) s=1;
                break;
            case 12: if (strcmp(CT, "YES") == 0 && strcmp(SE, "YES") == 0 && strcmp(EC, "YES") == 0) s=1;
                break;
            case 13: if (strcmp(HD, "YES") == 0 && (strcmp(AO, "YES") == 0 || strcmp(RD, "YES") == 0 || strcmp(CU, "YES") == 0 || strcmp(AM, "YES") == 0)) s=1;
                break;
            case 14: if ((strcmp(OT, "YES") == 0) && (strcmp(SE, "NO")) == 0) s=1;
                break;
            case 15: if ((strcmp(OT, "YES") == 0) && (strcmp(SE, "YES")) == 0) s=1;
                break;
            case 16: if ((strcmp(AG, "YES") == 0) && (strcmp(OR, "YES")) == 0) s=1;
                break;
            case 17: if ((strcmp(AG, "YES") == 0) && (strcmp(OR, "NO")) == 0) s=1;
                break;
            case 18: if (strcmp(HD, "YES") == 0 && (strcmp(CN, "YES") == 0 || strcmp(HF, "YES") == 0 || strcmp(HH, "YES") == 0)) s=1;
                break;
            case 19: if ((strcmp(GT, "YES") == 0) && (strcmp(SE, "NO")) == 0) s=1;
                break;
            case 20: if ((((strcmp(GT, "YES") == 0) && (strcmp(SE, "YES")) == 0) && (strcmp(GD, "YES")) == 0) && (strcmp(GC, "YES")) == 0) s=1;
                break;
            case 21: if ((((strcmp(GT, "YES") == 0) && (strcmp(SE, "YES")) == 0) && (strcmp(GD, "YES")) == 0) && (strcmp(GC, "NO")) == 0) s=1;
                break;
            case 22: if (((strcmp(GT, "YES") == 0) && (strcmp(SE, "YES")) == 0) && (strcmp(GD, "NO")) == 0) s=1;
                break;
            case 23: if (strcmp(GG, "YES") == 0) s=1;
                break;
        }
    }

    void put_var_into_ccls_queue()
    {
        switch (sn)
            {//CHECKED
            case 1:
                strcpy(AT, "YES");
                printf("AT=YES\n");
                strcpy(v, "AT");
                instantiate();
                break;
            case 2:
                strcpy(TR, "YES");
                printf("TR = rate-control drugs and anticoagulants\n");
                break;
            case 3:
                strcpy(TR, "YES");
                printf("TR = electrical cardioversion\n");
                break;
            case 4:
                strcpy(TR, "YES");
                printf("TR = electrical cardioversion\n");
                break;
            case 5:
                strcpy(CT, "YES");
                printf("CT=YES\n");
                strcpy(v, "CT");
                instantiate();
                break;
            case 6:
                strcpy(TR, "YES");
                printf("TR = cholesterol-lowering drugs & diet change\n");
                break;
            case 7:
                strcpy(AC, "YES");
                printf("AC=YES\n");
                strcpy(v, "AC");
                instantiate();
                break;
            case 8:
                strcpy(TR, "YES");
                printf("TR = bypass surgery, reimplantation of the anomalous artery, unroofing of intramural segments of the anomalous artery\n");
                break;
            case 9:
                strcpy(TR, "YES");
                printf("TR = Meication to strengthen the heart + Oxyegen Therapy\n");
                break;
            case 10:
                strcpy(CT, "YES");
                printf("CT=YES\n");
                strcpy(v, "CT");
                instantiate();
                break;
            case 11:
                strcpy(TR, "YES");
                printf("TR= ACE inhibitors and/or beta-blockers\n");
                break;
            case 12:
                strcpy(TR, "YES");
                printf("TR= Medication & Heart Transplant\n");
                break;
            case 13:
                strcpy(OT, "YES");
                printf("OT=YES\n");
                strcpy(v, "OT");
                instantiate();
                break;
            case 14:
                strcpy(TR, "YES");
                printf("TR= medication and lifestyle limit\n");
                break;
            case 15:
                strcpy(AG, "YES");
                printf("AG=YES\n");
                strcpy(v, "AG");
                instantiate();
                break;
            case 16:
                strcpy(TR, "YES");
                printf("TR= heart valve repair surgery & medication\n");
                break;
            case 17:
                strcpy(TR, "YES");
                printf("TR= Transcatheter aortic valve replacement (TAVR) & medication\n");
                break;
            case 18:
                strcpy(GT, "YES");
                printf("GT=YES\n");
                strcpy(v, "GT");
                instantiate();
                break;
            case 19:
                strcpy(TR, "YES");
                printf("TR= medication\n");
                break;
            case 20:
                strcpy(TR, "YES");
                printf("TR= Catheter procedures & Medication\n");
                break;
            case 21:
                strcpy(TR, "YES");
                printf("TR=Open Heart Surgegy &Medication\n");
                break;
            case 22:
                strcpy(GG, "YES");
                printf("GG=YES\n");
                strcpy(v, "GG");
                instantiate();
                break;
            case 23:
                strcpy(TR, "YES");
                printf("TR= Medication & Heart Transplant\n");
                break;
        }
    }

    string find_var_in_clvarlt(unordered_map<int, string> clvarlt,int key)
    {
        unordered_map<int, string>::const_iterator got = clvarlt.find(key);
        if ( got == clvarlt.end())
            return "";
        else
        {
            return clvarlt.at(key);
        }
    }

    void check_instantiation()
    {
        i=1;
        while ((strcmp(v, varlt[i]) != 0) && (i <= 35)) i = i+1;
        if (instlt[i] != 1)
        {
            instlt[i] = 1;
            switch (i)
            {
                case 1:
                    printf("YES OR NO FOR HD- HEART-DESEASE? ");
                    gets(HD);
                    break;
                case 2:
                    printf("YES OR NO FOR AR- ARRHYTHIAS? ");
                    gets(AR);
                    break;
                case 3:
                    printf("YES OR NO FOR AT- Arrhytm_treatment? ");
                    gets(AT);
                    break;
                case 4:
                    printf("YES OR NO FOR HV- heart_valve_disease? ");
                    gets(HV);
                    break;
                case 5:
                    printf("YES OR NO FOR RO- regular_occurance? ");
                    gets(RO);
                    break;
                case 6:
                    printf("YES OR NO FOR CA- Coronary_Artery? ");
                    gets(CA);
                    break;
                case 7:
                    printf("YES OR NO FOR CT- coronary_treatment? ");
                    gets(CT);
                    break;
                case 8:
                    printf("YES OR NO FOR HC- high_cholesterol? ");
                    gets(HC);
                    break;
                case 9:
                    printf("YES OR NO FOR AC- anomalous_coronary? ");
                    gets(AC);
                    break;
                case 10:
                    printf("YES OR NO FOR EM- emergeny? ");
                    gets(EM);
                    break;
                case 11:
                    printf("YES OR NO FOR CY- Cardiomyopathy? ");
                    gets(CY);
                    break;
                case 12:
                    printf("YES OR NO FOR RT- cardiomyopathy_treatment? ");
                    gets(RT);
                    break;
                case 13:
                    printf("YES OR NO FOR SE- servere? ");
                    gets(SE);
                    break;
                case 14:
                    printf("YES OR NO FOR AO- Aorta? ");
                    gets(AO);
                    break;
                case 15:
                    printf("YES OR NO FOR OT- aorta_treatment? ");
                    gets(OT);
                    break;
                case 16:
                    printf("YES OR NO FOR AG- aorta_good_overall_health? ");
                    gets(AG);
                    break;
                case 17:
                    printf("YES OR NO FOR OR- aorta_repair? ");
                    gets(OR);
                    break;
                case 18:
                    printf("YES OR NO FOR CN- congenital? ");
                    gets(CN);
                    break;
                case 19:
                    printf("YES OR NO FOR GT- congenital_treatment? ");
                    gets(GT);
                    break;
                case 20:
                    printf("YES OR NO FOR GD- congenital_defect_repair? ");
                    gets(GD);
                    break;
                case 21:
                    printf("YES OR NO FOR GC- congenital_catheter_repair? ");
                    gets(GC);
                    break;
                case 22:
                    printf("YES OR NO FOR GG- congenital_good_health? ");
                    gets(GG);
                    break;
                case 23:
                    printf("YES OR NO FOR CL- Cardiomegaly? ");
                    gets(CL);
                    break;
                case 24:
                    printf("YES OR NO FOR ND- Nonobstructive Coronary Artery Disease? ");
                    gets(ND);
                    break;
                case 25:
                    printf("YES OR NO FOR CM- Coronary Microvascular Disease? ");
                    gets(CM);
                    break;
                case 26:
                    printf("YES OR NO FOR OD- Obstructive Coronary Artery Disease? ");
                    gets(OD);
                    break;
                case 27:
                    printf("YES OR NO FOR YT- Myocarditis? ");
                    gets(YT);
                    break;
                case 28:
                    printf("YES OR NO FOR PT- Pericarditis?");
                    gets(PT);
                    break;
                case 29:
                    printf("YES OR NO FOR EC- Endocarditis? ");
                    gets(EC);
                    break;
                case 30:
                    printf("YES OR NO FOR RD- Rheumatic Heart Disease? ");
                    gets(RD);
                    break;
                case 31:
                    printf("YES OR NO FOR CU- Congenital Rubella? ");
                    gets(CU);
                    break;
                case 32:
                    printf("YES OR NO FOR AM- Acute Myocarditis? ");
                    gets(AM);
                    break;
                case 33:
                    printf("YES OR NO FOR HF- Heart Failure? ");
                    gets(HF);
                    break;
                case 34:
                    printf("YES OR NO FOR HH- Hypertensize Heart Disease? ");
                    gets(HH);
                    break;
                case 35:
                    printf("YES OR NO FOR MM- Mitral Valve Disease? ");
                    gets(MM);
                    break;

            }
        }
    }

    /* Search clause variable list for a varialbe (clvarlt) equal to the
    one in front of the conclusion queue (cndvar). Return the statement
    number (sn). If there is no match, i.e., sn=0, the first statement
    for the space is f. */
    void search()
    {
        flag = 0;
        sn = f;
        while ((flag == 0) && (sn <= 23))
        {
            cn=1;
            k = (sn-1)*5+cn;
            while ((strcmp((find_var_in_clvarlt(clvarlt, k)).c_str(), cndvar[fp]) != 0) && (cn < 5))
            {
                cn = cn+1;
                k = (sn-1)*5+cn;
            }

            if (strcmp((find_var_in_clvarlt(clvarlt, k)).c_str(), cndvar[fp]) == 0) flag = 1;
            if (flag == 0) sn = sn+1;
        }
        if (flag == 0) sn=0;
    }
    //==========================================================================
    /* Routine to instantiate a varialbe (v) and then place it on the
    back of the queu (cndvar[bp]), if it is not already there. */
    void instantiate()
    {
        i=1;
        while ((strcmp(v, varlt[i]) != 0) && (i <= 36)) i=i+1;
        instlt[i] = 1;
        i = 1;
        while ((strcmp(v, cndvar[i]) != 0) && (i <= 36)) i=i+1;
        /* variable has not been on the queue. Store it in the back of the queue */
        if (strcmp(v, cndvar[i]) != 0)
        {
            strcpy(cndvar[bp], v);
            bp=bp+1;
        }
    }

};


int main()

{
    string buff;
    Backward diag;
    diag.diagnose();
    printf("If there is any heart disease, HIT ENTER TO CONTINUE.\n IF NOT, PLEASE CLOSE THE PROGRAM!\n");
    getline(cin, buff);
    printf("If there is any heart disease, enter YES for HD- HEART DISEASE\n");
    printf("===> Enter YES for %s\n", diag.DE);
    Forward treatment;
    treatment.recommend_treatment();
}

