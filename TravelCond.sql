-- Script Date: 5/2/2021 1:07 PM  - ErikEJ.SqlCeScripting version 3.5.2.87
CREATE TABLE [TravelCond] (Q
  [tcid] INTEGER NOT NULL
, [verbSetId] INTEGER NOT NULL
, [c_verb] TEXT NOT NULL
, [obj] TEXT NOT NULL
, [objCondition] TEXT NOT NULL
, [action] TEXT NOT NULL
, [destination] TEXT NOT NULL
, [travelId] INTEGER NOT NULL
, CONSTRAINT [PK_TravelCond] PRIMARY KEY ([tcid])
);
