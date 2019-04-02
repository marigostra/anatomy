#encoding "utf-8"
#GRAMMAR_ROOT All
//PersonName -> Adj<gnc-agr[1]> Noun<kwtype="имя", gram="~гео", gnc-agr[1], sp-agr[2]> Verb<sp-agr[2]> interp (Person.Name);
PersonName -> Word<kwtype="имя"> interp (Person.Name);

// FullName -> (Word<kwtype="должность"> interp (Person.Position)) PersonName;


//Position -> Word<kwtype="должность"> (Word<kwtype=~"имя">*);



Position-> Word<kwtype="должность"> (AnyWord) Adj<h-reg1> Adj Noun (Word<kwtype=~"имя">) |Word<kwtype="должность"> (AnyWord) Adj<h-reg1> Noun (Word<kwtype=~"имя">) |Word<kwtype="должность"> (AnyWord) Noun<~h-reg2> (Word<kwtype=~"имя">) |Word<kwtype="должность"> (Word<kwtype=~"имя", ~h-reg2>); 
PositionInterp -> Position interp (Person.Position);
// FullName -> (Position) PersonName;

PredPosition -> (Comma) (Word<kwtype="предикаты">) ("на") ("в") ("пост") ("должность") Position interp(Person.Position);

Punctuation -> Punct| QuoteSng|QuoteDbl|LBracket|RBracket|Hyphen|Comma|Colon|EOSent|'\\'|UnknownPOS;
// Города
S -> Word<gram = ~"persn,famn,patrn"> Word<kwtype="города", h-reg1> interp (CitiesFact.Name) Word<gram = ~"persn,famn,patrn">|Word<gram = ~"persn,famn,patrn"> Word<kwtype="города", h-reg1> interp (CitiesFact.Name) Punctuation| Punctuation Word<kwtype="города", h-reg1> interp (CitiesFact.Name) Word<gram = ~"persn,famn,patrn">|Punctuation* Word<kwtype="города", h-reg1> interp (CitiesFact.Name) Punctuation;
//S -> Word<kwtype="города", h-reg1> interp (CitiesFact.Name);
S1 -> (Word<kwtype="префиксы"> interp (CitiesFact.Class)) S;
S1 -> Word<kwtype="префиксы"> interp (CitiesFact.Class) Word<h-reg1>+ interp (CitiesFact.Name);
//Страны
Countries -> Noun<kwtype="страны", h-reg1> interp (Country.Name);

All -> PositionInterp (PersonName) | (PersonName) PositionInterp | Countries| S1;