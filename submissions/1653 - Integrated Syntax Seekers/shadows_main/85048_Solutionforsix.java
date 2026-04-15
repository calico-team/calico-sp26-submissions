import java.util.*;
import java.io.*;

public class Solutionforsix {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
      
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            String[] S1 = new String[N];
            String[] S2 = new String[N];

            for (int i = 0; i < N; i++) S1[i] = sc.next();
            for (int i = 0; i < N; i++) S2[i] = sc.next();

            long Maxvol = 0;
            long Minvol = 0;

            for (int i = 0; i < N; i++) {
                long R1count = 0;
                long R2count = 0;

                for (int j = 0; j < N; j++) {
                    if (S1[i].charAt(j) == '#') R1count++;
                    if (S2[i].charAt(j) == '#') R2count++;
                }

                Maxvol += (R1count * R2count);
                Minvol += Math.max(R1count, R2count);
            }

            System.out.println(Maxvol + " " + Minvol);
        }
    }
}
/** *WWWW888%%%B%%%%%BBBBBBBBBBBB%%%%%B@@@@@@@@@@@@@@@BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB@01112222233222111222220@B%%BB%88WM##*ooaahhkhhaaooabppdd
WWWW88%%BBB%%%%%%BBBBBBBBBBB@@@@@@@@@@@@@@@@@@@@@BBBBBBBBBBBBBBBBBB@@@@@BBBBBBBB@@@%BB@@$01111222111000000@B%%%%%8WW##**oo########**oakdddd
WWWW8WW8888%%%%%%BBBBB@@@@@BBB@@@@@@@@@@@@@@@@@@@BBBBBBB@@@@@@@@@@@@@@@@@@@@@@@@@@@@$$$0122222222111211110@B%%%88WWM##*ooakhhaaooo*##ohddbk
W888WMWWWWW8%%%%%%BBB@@@@@@@@@@@@@@@@@@@@@@@$$$$@@@@@@@B@$%%@BBBB@@@@@@$$$$$$@@@@@@$012333333322222111100$$@@B%%8WWWMM###*ohkhaoaaa*M*akbbb
WW8WMMWWWWWMWWWWW%%BBBBBB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$@@B$$$$$$$$$@@BBBBB@@@@@@$011233333322211122111100$$@%W#oaho#M*oohbbhaoooooohkkkk
WWWWMMWWWWWWWWW888%%BBBBBB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$$$11@$$$$$$$$01200$$@@$$$$$$$0122333332221100$$$$00$@@B%8W##o*#MMWW#aaoaoooahahkkhk
WWWWWW888WW888888%%BBBBBBBBBBB@@@@@@@@@@@@@@@$@$0$@$Boh#pTiiilil;,,:ilI;ilfLCZ8101$$001332222322210000$$$$$@B%8WM#*ooo#MW8BWoobkoaaakbkhaah
WWWWWW888WW8888888%%BBBBBBB@@@@@@$@$$$$$$$$$$$010$BbQ|;l!!II!l;I|;:;iIi;;;IlIi;;i1Z#M%011222232221111100$$$@B%8#*oaaao#8B@B8##hbaaoohbhaoao
WWWWWW888WW8888888%%BBBBBBB@@@@@$$$$000$$$$$$%awQJJf!i!C1;,i!I|l|liIiiiiliI|||lIII|TdB1112333232221111100$@@B%%%%8WM##W%B@@%MW*baao#okhoooo
WWWWWW8888888WWW888%BB@@@@@@$$$$$@$0100$00@*0l:;ilIi;!1li;!1l!|IlllIl:I;:;III;;;;;i;I1TO1942322222210111100$$@@$$@%8%WB%@B8WWWWkkho*#ahoao*
WWWWWW88888%8WW88%%BBB@@@@@@$$$$@$011001%okCI.,i|Tf1||I:,:I|l!lIllliI:I;.,:;i;::::;,;Il|Lh443033322100000$$B%B@3442$BB@B0@%88%Waao*##oa*o*#
WWWWW888888B%888%%BB@@@@@@@@$$$$@01110$#f|I;::lTTJl;I;,:;;;;;;iI|1fJCiIiI;::;iIIIll;lQl,:|q1443333321111120@B$03563$@0$$3$B%%%%***###*oM##M
88888888888BB%%8%@@@@@$@BB@$@@@$$$1$100q!l!!li|1f|;;;;;:;l!l:;;il!TLmT||J!f!ll:;|ll|fQC:llJM393303033333332111258731132220@%%BBMMMMMM##MMWM
88888888888%%B%BB@@@$$$@BB@$@@$$$1222$mfC|II;IT1T1IiiiI:,:lfCI;,,il1C0I||LqZ0!;;;:iliTJ;I|iII1*2114233333321112365321433300@@@BWWWMM####MMM
88888888888%%B@@$@@@$$$@BB@$@$$$$121$dTTCT;;;1Qf|iIi;iIiiiI|TI;;ii:IlL!|l1m0ZJ1!lI1|i!l;IIIT1|!m#3443333343111224433254441100$%88WM##*###MM
MW%%888%%%%@@@@@@@@@$$@@@@$@B@$003@@WZ|JL!:IT|l!Tf1T||!l;iCLi:;|llT!!Omff11TC||Il!fTJJ!ii;|Cf!1TTk*B633423322111311354644225$$888WWM#***#WM
WW8%%%%%%BB@@@@@@$$$$$@@$$$$@$$01111M0T0mfIf|il1T11TfC1;IiiTL|l!LZwwdhh*kLwZQ|I|11ffTlTJII!1TQQL|TTO@54144332210134554533135$$8WWWWWWM###MM
%8W8%B%BBB@@@@@@@$$0$0$$$$$$$$01121BpJf0LT!JJ!llII|fJf!!CC11!T|!q#*#MM%$113$hph0wZZQilIJCT1ffL0QffJC@C2454443333245444533144008WWW888WM####
M88W1@@BB@$$$$$$000011$$$$$$1111230hC|ff|l1T1iil;;!flI1CCTI;;1|q*@B0126BB996520B8W#adq0pw0QZ0OZ0Lf!L*95856655775777645653223$0WMMMB%%%W**M#
M%%W0@@BB@$$$$000001110000001112214hT1LCl1CJf1|i;Ilii1fT!l;i||Oka8@0468AEGJID7522322@M%%0B%#aBWk0lTQA697A8877897998866654432208WWMB%%%W#*M#
W%%W1@@BB@$$0000011111110000112221%0TOhC!1fLTQCI;;;iI!|Il|IiIfmdkk8@0148JMOLA753332220114458A8874#fQ28BBBAA9ABB9BBAA9866676633BWWMB%B%W#*MM
W@%%@@B@@$$$$12221112211110012332@0fCOdCLCC1J0JTI;;iiI|!!II|:Tddqq8B@047FLMD754332122233348DHJGFCBJd86DDCCCCCCCBAABCB99658AC2618MW%%0%***WM
8@BB$@B@@$$0$$0111111222111123332@dLOZTOwCwZCJTi|lI::II|JJ|;;f0dqo8B@02386622@0123323355535BGHIDA8KHDDDCCDCDCCCCBBCDBA96599D342BW%%B$%*#*M#
%$B@0@@@$$01$B@$001111322211233322qLCQqmwkQL1JLJ1II:,;|||T1lT!Zkk#%B$$$@$B$01@@$011333222245AFHE86FJHEDEFEEEDEDCCCDECAA7698E5130W@8BB8#M###
@@@@@@B@@$00$%%$100000323333324402hf1wqCqQQf|1TJi.::;iI;;I|lIfLpaM%%BB@@B$4$0@@$0111221$%88#M@5A329KHEFFGFEDDEFFGGECCA779A8G5031BB%@%8##M##
@@@@@@B@$00@01$$000000323333333330$M6B01.1CC!I:;::;;;I|IIl!11fZb#MW%8%%%@02@$@@$$012221100$8W%0$31CLHEFEFFEDDEFGHGFCA988AA8F6212$@B@%8M#M##
@@@@@@@@$0002311100000323333333358oqmq18k!1Tf|!Ii,IIIl!TTfC0Zpk#MW88%B@$24112222233322243310@B%0500DGDFEFFEDDFGJJIFC99AABBBD43251$B@8%MMMM#
@@@@@@@@$002232000001133333423428kmpbhwd$@*0BWfiI;I;1I1L0pkkMWM#MMW8%B4BB8333112368B9424344272341GBIFEEFDDECDFKNMHDB7AAADCD8325841@%%8WMMW#
@@@@@@@@$00123210000113333333335@wbqa#a00%kfl;,1b5%l:!0dkh*M8****MBB07FIHF7541$0146BAIQLD844568DRRCHFDDEDCECCEKNKFDBBBCHGB84357454@WB8WMMW#
@@@@@@@@$000123220111133333334358pbM22BamWow1Iil;I;L@G3#bkMohaMMMB1335AF62773320@@@$78IPNKFEDEFJQSMJFDDECBFDBDLNHDDADBEE96647A86784B%8WMMW#
@$$$$$@$$00112222112222344333342%ZB$M@BkOb#d0!1|iIllITma9PCohaM8W18%amLQQJ00mOa8W%@3441%6B75328HRROMEEFDDCECAELREBCBBCI99988CG766A83%WMW8W#
@$$$$001122112222222233344333242@b1hdZZZTLwZqOJiiillIJMB#haW3IH@!!1JIT6Bp%owmqa*B@761@8o%%8%%%8B56DMIFEDECEDBDHNMLDA8HGA9979HH676AA94B888W#
@$$$$0011222222332233334554332331b@bbdZQQ0B4*fi::iillCB%*oodwwqqB1b@71hJ|T|I1!1|1!fiJJhBA81$%8B$0136FFDDDEDDCCCFHMCAAJKA9AACGL9869ACA2@88W#
@$$BB$000112222223334444444432673koMWo*Lfk*W!Il||I1I1CM*oooaadwqwZm#a1TILQ;,|!1l|T0EL9#%kdbdQi8*mbB9ORNHAEEFDDCCCDC89FK7C7ACFHFA77ACC74@B%#
@$$@@0222232222223344444444443564%ba827MO#kJlll!|JlLZdh**oahkkbkbhd8Off0ZpwJfOOfLJfT$GGdBkO|ob!ObCq*@7769GFCDDDCCFGEBEIE9ACEFFCGD98AAB92$8M
%@$@01112222222223444455545554456%ok@B@4aQ|lTfl!C!1JLmkaaahhh*BBM%1#mZQCT|1T!!TfTTTw7IHo%AGNd|1TLDPIC833886HECECCEGFGDDGEBBFGFA9BCB99CD84@W
B@0101121$@@%B133555555455555656642BM*p#Q1!LlifQ!|!!CmOkkkkaoh%5$%7mmZQ0mOLCTCLOO1WILM%pa1O3Z#q$1qLPKC9E9J@JFEFCCEFGGHEADHCDJGDBAAA769BB91%
%@01111221088@134555555555555556666##hqOJJ0l,1L|lJ|1JCQdbbkhh##B2B$mOZmm0O0OQZLZ06G$papb54@8JZk10FMQTSEAHU6KCGCEEGGHFEC9BFEBFFFFEDB997ACC3%
%B0233221$B@03345555555555555555567hmbbLCfI||f1I!f|1||Qwpdbbdkah**2#Q0QfLLCLC0kdpL|BdmkhB9Ebmph8FMURVNCETNCFGHEFFFFGFECBCDCCEFEDECAEJDABB4B
W%B$$121$@@234444455455775468887677wW8B0Tf1!LTll!!T|I!QLmpdbbdbkkbbmMaffffJLCCmCf0kZqbk*MAG8hpaCOPPRTHKSNHHGGEEEEEFGGFDDDEFEEEFEEB9CGJ5B83$
%%B$022100133445554566545GOIGJ90Wkow88kLJfJ1L|i;T1|liICCZwwqwwpddppwZ0kW*ak#aqkkqQ0dkhoM%3DKWMW1CBFMKMVRJHGGGGGGHIJJKJHHHHFEEDCCDDCACM7673$
@BB@133223434455567535HORG4DJS4pmakM70bC:T|L|i|!!i|II!JTLOOZOmqdbbkpkbbhobbbdp0TLObaho8$04AH3B$8DEHINTLHGGGHHIHHLPQQSQNKJIHGFDCDCFHCGI96820
@@B@$000134445565772DQSMJO5CDD8mo%*$3Wk!|JC!IlI|l!TI!TCl!COZZqdkkkkbaapda*hdqZCmko#o*#@5F8KIJIIJKKJKIJGFFGIIIIKOQQOOOONNMNNNMJHFFGIHKDA9843
@@@@@@@@$1344556532GA@$01ZMDI8aCqhh018p1CC!II|Tl!Tl;Il1i|JOwqdbkhhkkaohkabkkkmJZh*#oaho*5649DHDDEEFFFEFGGGIJIJMPPNLLLMMNNNNNNMLLLNPMJDA9965
@@@@@@$$024445563C3146dw%Bh*A1o9k0*WWMZ1;Cl||l!|I:Il!l1i|fJ0wpppdkhoakhbdboadqm0CI,i|CqbMM2EAGDDCBABCEFFFFIJJLNNLKKJHHIIIJKKJKKLMOLHDCAAA88
@@@@@@@@0243426546$@#5DqCq%BBb$6dO8#odwifTfT1m0T:IIII||;1!|fQZmqdkoadpbkqZQC1ll|1|;;|fJp$039IEDCBBCCCDEEEHJLKNNKKJJKKJHGHIJJHGJKMLFBABAAAAB
@@@@@B%@$01256657h*obqWhkLCh%MW%doWWkLZ;C|l1Jp!:IIli|llilll|JCLOmpbokmQC!!||IiIliil|I11fw#AFHDDCBBBCBCDEEHJMLONKKIILKHGHJKKKKKMOMJECBBBBBAB
@@@@@$$@B@@013558dwkdwQZOqqQTJOO8A6#mfI!iI||!Jli1ill|l|I;iII||TLZqbdQC1l|Ii|T1l;iI;l,IJJQO@AMHCBAAABBCDEEFINLNMKLKJKOLJMNNOOOPNKIFECBBBBBBB
@BBB@B%4DBAEACB61q00pqZqqZwqdZCfTQ*9h1ITi|IlJJTII,!Till::i;lIlI1CCJCf|IliI!T|l!!|!i!::|JCb*24RKA9AABBBCEFEHNLKOKLOOKPPNPPMLKJIGEEDDCBBBBBAB
$@@3992oOd##382kkdOCJJpqwdwwZwqpbpOaEZI||;:l|TIl;i!IlI:;:;;I|iIl!1fTf;ll:|!!!TCff0mwwQlZJfkwk5QDAABDCCABDGFHMNLNMMNPMRPNJIHGGFEFEEDCCBBBBAB
Madqqqqpwf|!0*$*qQLLTf1fqwpwO00LT1qOa3T||,;!1!!II1!ll!:;:;,I!;|iI|!1|iIIII!CL1iiI|JOZ0lLCLO84@FCABABCAACEDHGIMMNQQOORSLKHFFFEEEEEEDCCBBBBAB
0BMakppmwmZZLqahbZCTQCJ!lT0OZ0LCff0OQWoLI,l!1l|Il!!I!l:i::,||IlI|!II:I;II|fQmqqwdwb#d1C0L|OkD8KC8GKHINQKDGHGHLNQRPPQPKDEEDFEEFFEEDDCCCBBBAB
$%M*ohdqmOQOOmbbqmbm1CLLJ!l|1fffTTJCJq8kf!!|!!l1!|lIiI;;;i:|lIll||I;::;Il!!|fmahao12*|QQLlmbm8JKKJIHFFHQRKKJJLMOTSQJDCDEFEEEEEEEDDDCCCCBBBB
B8*hkdqqm0CCQQwkkmOOqfLQQLfT||!!!fQLJL@aJ!1T1T|!!Ii;;IiIiI|IIil||lii:::;II|!i  ..iQ*O;1OCJJZFFGFFIIHC8D9DRRJLNJQVNHEDFGFDDEEEEEEDDDCCCCBBBB
ahkbdpqdkdwqQCQZk*pQQ0OT!TTfJJTl!!0J1TdWZ|!J|T!!|Ii:IliIiiC;I;I|lii;:::,llIl|i,.,Ifqll1!Od*5446675546%0954IVTRUWQHHEEEEBDDDEDDEEEDDDCBBBBBB
ddppqqwpkkdhOLLL0h*wTfL0CJ1TTJJLfCJ1|1Jk8fJC!!T!iii;illiIif;iil!li;;:;;:iIllI;;,;I1Ci .,!m1BB5$1$MhW226G35DNTYWWQPDDCJJMFDEFEDDEDDDDCBBBBBB
qqwwmmmZpkaaZQQQ0ZkkZf!L!QqJT!JCLC||!1JJ*p!!!11;;;ii;;lIiil;iIl|lI;iiiilIlllIiIil!TOC;iIf8C78@01hIpa**B*WLOQVURUST9ABDDFNDDBCEEDDDDCCBBBBBB
pqwwwwZOmk#Wd0LCCLqbdwLTQ!JZLf1fJll|JQLOLaqiiTl:I;;;;;lI;ii;I|||liiiIIl|ll|llIll!1T0qLIfa798B08Z.IfmpwJ#8WWCERTSTJABCCBFFKMJEDDDDDCCCBBBBBB
bdwwqpqmZd#%am0LLL0mddZOf!1|LqL!!!11J0QCCJ#o|||l;Ii;iIii;iIil|1|;:iIIllllli!!IlI!1!!pbmZ8#WWkZ0$K1qTfJ1Zw01WpEE8966A8AA878BFLDDCDDDDCBCBBBB
kbbdddpqwpa8Mhm0QLL0Zppw0J1||JLQJZmQJf1fl1!qwJIIilliiI;i;iIill!I,,:iIlIilI;!f|ll!T1!Jd*ibMoabp0CC%kpJ1fJW0wM6%ok@B25EA888669IJIDCCDCCBCBBBB
kkkbddbdqqb8%#dOQL0QQOpdwOLT|I||!JOOLf||f1!1LqO|;I|iIi;;;iIilIIi,.,iIli;IIil11ll11TTJmwZmqddkmOOL88888W$51BaZpbW5FGNE8$2434349FGDBDCBBCBBBB
kkbbbbbbdpd*8MamZ0QLQ00Zwm0Lf1|lIil|J0Q1ll|I1O0ZT:i:|ii;;i;iIIl:,.:iiIi;:ii||11|I|1Tfmkp0!ZwOZQLB2132430oqo08wpk@38A7o#456410027EDBBCCCBBBB
kkbbbbbbdpdbohbmmO0LLQ0OZZ0QLLf!ll;::i|!T1||fmb8T,,:!IIi;;iIiI;:: .;;III::;|l|1!!|||1w#hkJ;QwLLM3647D91pOb*%$%bmOM91qM43642212207FCCDCCBBBB
kkkbbbbbdpddkbqOZZOQLLLQOOZOQ0Lf1iilI;I;;l!1CCCqM;:i!iii;;Ilil,;; .;;III;,,llI1!|1!|TJOhkhO1owZ3446AB1aJo##*CC3plTQoBB112231$$042BDCBCCBBBB
kkbbbddpppqpdkqOmZZOQQO0OZ0QQ000QJ1liiiIi;;iii|1M*Q1TiI:::;l|l.:;:.i:;I;:,;III!||l||fTOQqadLpWW1356608mM#@3A21aOk#o88B0011@$M8@$049EGCCBBBB
kkkbbddpppqwqbqZwmqmZ00mwO0OQOZZZmmOJl;;;iiii;;:I1JTTJ!l;,,ilI:,;;.i::;,,.:IIi;iiIi|J!Q0mhqJdaMW@11@*ZaB419D%Q1wwW1$0BB1@wqhWW$22116DDDCBBB
aahhhbdppqqmqdqmwwpww0LmqZZwZmwmZZZmmmZf|;;i;i:;.;;;11Q0|:.,;I|:.:,i:,:.,,:iii.:;i:!T!JampO0wa*#M@1b1p*B25A%b1qqq*MB8%8w|C0OQQd@$@037CDDCCB
hhhhhhkdpqpqwwppqdpqmmqwZ0QQLQZOZZZZZZZ00LTlii;:,,:,;l!fTIi.i!:l,;:,,:::,:::;;,i,I;I1!!0ww0mmdo*MBMOfk#W218*Cpo#WWM#mll!l1TLQOwdao*$269DCBA
hhhhhhkdpppwmmqwqkbpwmZwpqZ00OZ0Q00000OZZOQJ1|i::;:;,il;!Ji:ii|;i,:,,:::.::,;;,i,i|I!||IamZwb$BopopQmk*o*8k|Oqo**WbT11!!!|!fOddqdkpB@335ECA
hhhhhhkbpppwZmwwwdddppwmZOO0LLO0OQQQQQQQ0OQJf1I;;;:,,;11lJ!,:i.1:;:,,,::.::,:;::I.fI|;T:aaZChaWWwb0JmpaBWMl1qbh%W0Tf!T1!!l|TCOdbwwp*WB16AB8
hhhhhhhbdqwwZZmmmpdbdqmmZmwmQQOQ0QQQQQQ0OOO0CT!!l;;i:il|I1O:,,i,I!i:,...::,,,:,;i.il|I1JfWkZZ0pbZLCLqm*B8fITQwbdC1TJf1!|!!!|1CZqOZmd##2268C
hhhhhhkbpqmmZZmmZmqpddwwmmwwZZm0OO00QQLLQ00Q0LJf1|II;iI:|IC1i;.i;::;,   :,,,,,.:;:,l|llfCd$wwq00CLLpMwhok;JfLqwfJJfCf1!|!!!||fQqZmwmkd8$31$
hhhhhhkbpwmmZZmZOZmqbkbdwZZmwmwZZmmZO000ZwwwZ0LCJ1ll;iIi;i11J; .;::,...,,,,,,..,i;.,|.ITJqqZZ0OLCCLpbqOpwOQfwoZCf!TTf1!|!!!111!|CmZwdkd@W8o
hhhkkkkbpwmmZmOwmmppbdkdqmZZmwqwpqwmmZZO00OmZO0QLC1liii:,:i|11;,.;...:, ......,:::,,l.:!JOOmQOO00QLCCQO0L0ZpqwOZZO00QLCf1!|!!!!1LOOmd*d%%Mp
hhhhhkbdpqwqmwZwwwdbbkkbdqmZZZpdbdpwmmwmZZmwmmZO0QCTlii;:,:ii|fI;.,.,:, ......,:;:,,i;;i|ZZbfQ0OZZO0QLLQ0ZZmOZ00OOQ00QLJfT|!!!!1C00mbka#8%h
ahhhhbddppqmZwwbpwdbkkkkkpmZZ0qpqdqZOmwwwqdkpwmZOO0J|i;ii;;;ilICI:,,,:, ......,:;:,;Illi1fqLLOC0ZZ0Op0QL00QOOmmm0CLZOO0QLC|!!!!!JLQmhW*b#8M
aaaaahkkbbbqpppbkbbbkkkhhbqmZZwpqpqmmwqqdkhhbpqqwOZ0flI;;;;;;;Il1;:,.Ii,.  .,:;;i;:;i||;imCLC0QOmm0LQQ0000OOOmqqqbhkkdwOQLL!T!TfOQZb*8MppW8
aaaaahhhkkkbbbdbhkkhhhkhhkpwmZqdpkbdqmZdkaakbdpdpqmwOJTlIIIII;;I!Ii:.,|.,. .,;iii;,:,i::i!LQ00OmwOCCQ00OO0Zmmpkhaaakqqqm0Q0T0fTfJLba*W0wkB%
aaaaaaahhhhhhkbkhhhhhhbhahdqmmqdpdppdbbhhhhakddbbdw0ZwOC1I:ilIiIIi;::.l:,...:iIIi:,l;lil||C#QCOZOLQ000OOO0Zmwbhdqkb0LOqqZ0OJL0TJ0QbohoWaM8%
aaaaaaaaaaahhhhhhhhhkkbkhhkbpwmqdbbbbhahhhhhkkkbbbpqqwmZQTi:;II;Il;l:::I...,,:ili;;I;||!1!TLmLJ00Q00OZmmwmwdhahkbdpppwZmmmwZZOQOZZLQLhooW8@
aaaaaaaaaaahhhhhhhhhkkkhhhkkbpwqdbdppdbkkkkkkkkkbbdppqwwmQTl:;iI;;I;!.,:.,:;;iil|I:|i!|JQCOTOCTQ000QOmwwmmbbqmwddddpbpmZmqddqOQQO0LfJaahM88
aaaaaaaaaaahhhhhhhhhkkkhhhhkkdqpdhkbdbbbbbbbddddppddppqwZO0Ti:,Ii::li|,,.,:iIlIiIli|ilTfC|m!pOL0LCQQOZZ0L|hmqZqddbbbdbdmZwbakwZLOOOJQkahohq
aaaaaaaaaaaaaaaahhhhhhkbbbbhhbpppdbhhkbkbbbbppppppppppbpwmZL1; .,::i;Il.;:iI|IIIl!liT11dCICCQO000OOQQ0Zwbbqmwqpdbddhhkdwmmkkhkbddddddhaa*pO
aaaaaaaaaaaaaaaahhhhhhahhhhahhkbppdkhhhhhkkkpdbbdpqqmwbhbqmOQl.  ...:;|:;;i;IIlII|!f1CJd1Cw0OO0QLQOZmwpddZmwwpbbdqdkbkhbqZwdhahhhhhhkahkkZL
aaaaaaaaaaaaaaaahhhhhhhhkkhhhahbpqdkhaahhhhkkbddbkqpqmmhbmOO0T:. .,,:.ii;II:Il|liITJLQqmQ0p0Zm0OmmZOZbaapZZwbkbkbbdpkhhbpqwpdkhhhhhhhhhhhwQ
aaaaaaaaaaaaaaaaaaaaaahhhhhhkkkkkddbhaahhhhhkbkhwqppwOQmdw0L!l: . .,:,;l;;;lTlI!IlJ|!ZdhwOmmpbkkm0OOmpdwOmZqdbhkbbbbddphhhppdkhhhhhhaahhkZL
aaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhhbkkhhaahhhhhkkhpbbbpmQCL0OQLI;,  .,,.,iiI;l|1Il!lTTZmdMdddkhhhkdmOmwqpppwwhkdkhokphaahoaahkkkhkkhhhhhahhpZ
aaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhhhhhhaahhhhkkhdakbbdpOmmZmLl|i,,:;;,:iTLT!|!i!TJO1wpb*aa#aabbdkpmbbpqqpdwwpdkhkbbhbbdhbkhhhaohkkhhhhohahd
aaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhkkhhhhhaaaaahhhkkkkkbbbpwqZZZ|1Tl:Il|;i||J0f1!T0Q0ZLpbkkooo*hkhaahkbpbmmpbbbbbdqqqqqwwwwwwqmmqbkhhhhhaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhhaaaaahhhkkkhhkkkqdddqqOqOmfLLJiI!I|1fiJf0Qmmqhookh*h*hhaaakdqwkdpdkkkkkkhhhhhhhhhhhhhhhahhhhhhahhhhh
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhaaaaahhhkkkahhhhakhZppOmOZZqqwT|li||0LLZOOqkakhakhakhhaaahbpwmddkhaaaaaaaaaaahhhhhhhhhhkhhhaaaaahhhh
aaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhhhhhhhhhhahbdbq00OCOObq0f1QJfmLpmpkaaahhhhhaahbpkohpwbbkhaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhbpkwmZ0mwqbqmQwqLLZkpkhhaahhhhhaahbbkkkbkhhhhhaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhhhhhhhhhhkhabwkmmmpOQdppkwbdwCmakaahaahhhhhaahbhhhhaaaahhhaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhaaaaaaaaaahakhkhhqwqdwmdakdbhkbqwahaohaahhhhaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*/
// just for reference this is supposed by asci art i got distracted and it looks bad but uh yea here it is 