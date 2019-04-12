
#encoding "utf-8"
#GRAMMAR_ROOT All

//All -> Noun<gnc-agr[1]> interp(Organ.Name) Noun<gnc-agr[1]> interp (Organ.Char) ;
Ent -> Adj<gnc-agr[1]>+ Noun<gnc-agr[1], rt> interp (Organ.Name) ;
Ent -> Noun interp (Organ.Name) ;
All -> Ent interp (Rel.Name1 from Organ.Name) Verb interp (Rel.Type) Ent interp (Rel.Name2 from Organ.Name)  ;

