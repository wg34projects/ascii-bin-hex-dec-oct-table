#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Aenderung 06.10.2016 auf implizite Datendeklaration bei den Schleifen C99 Standard

void binaerzahl(int nummer);

int main()
{
    char *rv;
    char format[6];
    char ch1, ch2;
    int start, end;
    int error1, error2;
    int formatlength;
    int ascii, hex, bin, octal, dec;
    int rv_start, rv_end;
    char error1text[] = "wrong input, bye bye...!\n";
    char error2text[] = "wrong input, take correct range and only numbers!\n";
    char spacer[] = "   ";
    ascii = 0;
    hex = 0;
    bin = 0;
    octal = 0;
    dec = 0;


    // do while Platzhalter fuer spaetere Aenderung von return -1 Abbruch auf erneute Eingabe
    do
    {
        error1 = 0;
        printf("THE extented ASCII TABLE GENERATOR - Codepage 850\n");
        printf("please choose one up to all options - upper or lower case\n");
        printf("(A)SCII, (H)EX, (B)IN, (O)CTAL, (D)EC - ");
        rv = fgets(format,6,stdin);
        formatlength = strlen(format);

        // Abfrage aus Codebeispiel Vorlesung 04.10.2016 - NULL als Pointervariable = Fehler bei fgets Eingabe
        if (rv == NULL)
        {
            printf(error1text);
            return -1;
        }

        // Abfrage ob der String mehr als 5 Stellen hat (maximal AHBOD) bzw. nur eine Stelle = ENTER
        if (formatlength > 5 || formatlength == 1)
        {
            printf(error1text);
            return -1;
        }

        // Abfrage teilweise aus Codebeispiel Vorlesung 04.10.2016
        for (int j = 0; j < 6; j++)
        {
            ch1 = toupper(format[j]);

            if (ch1 == '\0' || ch1 == '\n')
            {
                break;
            }

            if (ch1 != 'A' && ch1 != 'H' && ch1 != 'B' && ch1 != 'O' && ch1 != 'D')
            {
                printf(error1text);
                return -1;
            }
        }



        for (int i = 0; i < formatlength; i++)
        {
            ch2 = toupper(format[i]);

            if (ch2 == 'A')
            {
                ascii = 1;
            }

            if (ch2 == 'B')
            {
                bin = 1;
            }
            else

            if (ch2 == 'D')
            {
                dec = 1;
            }
            else

            if (ch2 == 'H')
            {
                hex = 1;
            }

            if (ch2 == 'O')
            {
                octal = 1;
            }

        }

        if (error1 == 1)
        {
            printf("%s", error1text);
        }
    }
    while (error1 == 1);

    // Sicherheitsabfrage Start > Ende eingearbeitet, ebenso ASCII > 255 und < 0
    do
    {
        printf("specify start and end of the table range is from 0 to 255\n");

        printf("start - ");
        rv_start = scanf("%d", &start);

        // Abfrage aus Codebeispiel Vorlesung 04.10.2016
        if (rv_start != 1)
        {
            printf("%s", error1text);
            return -1;
        }

        printf("  end - ");
        rv_end = scanf("%d", &end);

        // Abfrage aus Codebeispiel Vorlesung 04.10.2016
        if (rv_end != 1)
        {
            printf("%s", error1text);
            return -1;
        }

        if ((end < start) || (255 < end) || (0 > start))
        {
            error2 = 1;
            printf("%s", error2text);
        }
        else
        {
            error2 = 0;
        }
    }
    while (error2 == 1);

    printf("\nhere we go..............................................\n\n");


    for (int k = start; k <= end; k++)
    {
        printf(spacer);
        if (ascii == 1)
        {
            switch(k)
            {
                case 0: printf("NUL  ");break;
                case 1: printf("SOH  ");break;
                case 2: printf("STX  ");break;
                case 3: printf("ETX  ");break;
                case 4: printf("EOT  ");break;
                case 5: printf("ENQ  ");break;
                case 6: printf("ACK  ");break;
                case 7: printf("BEL  ");break;
                case 8: printf(" BS  ");break;
                case 9: printf(" HT  ");break;
                case 10: printf(" LF  ");break;
                case 11: printf(" VT  ");break;
                case 12: printf(" FF  ");break;
                case 13: printf(" CR  ");break;
                case 14: printf(" SO  ");break;
                case 15: printf(" SI  ");break;
                case 16: printf("DLE  ");break;
                case 17: printf("DC1  ");break;
                case 18: printf("DC2  ");break;
                case 19: printf("DC3  ");break;
                case 20: printf("DC4  ");break;
                case 21: printf("NAK  ");break;
                case 22: printf("SYN  ");break;
                case 23: printf("ETB  ");break;
                case 24: printf("CAN  ");break;
                case 25: printf(" EM  ");break;
                case 26: printf("SUB  ");break;
                case 27: printf("ESC  ");break;
                case 28: printf(" FS  ");break;
                case 29: printf(" GS  ");break;
                case 30: printf(" RS  ");break;
                case 31: printf(" US  ");break;
                case 32: printf(" SP  ");break;
                case 127: printf("DEL  ");break;
                default: printf("%3c  ", k);
            }
        }

        if (hex == 1)
        {
            // Formatierung von Codebeispiel Vorlesung 06.10.2016
            printf("0x%02x", k);
            printf(spacer);

        }

        if (bin == 1)
        {
            binaerzahl(k);
            printf(spacer);
        }

        if (octal == 1)
        {
            // Ausgabe angepasst an Codebeispiel Vorlesung 06.10.2016
            printf("%03o", k);
            printf(spacer);
        }

        if (dec == 1)
        {
            printf("%3d", k);

        }
        printf("\n");
    }
    return 0;
}

void binaerzahl(int nummer)
{
    int zahl, rest, stellen;
    int binzahl[8];
    int i = 0;

    do
    {
        rest = nummer % 2;
        if (rest >= 1)
        {
            rest = 1;
        }
        else
        {
            rest = 0;
        }
        zahl = nummer / 2;
        nummer = zahl;
        binzahl[i] = rest;
        i = i + 1;
    }
    while (zahl != 0);

    stellen = i - 1;

    if (8 > stellen)
    {
        for (int k = 8 - stellen; k > 1; k--)
        {
            printf("0");
        }
    }

    for (int j = stellen; j >= 0; j--)
    {
        printf("%d", binzahl[j]);
    }
}
