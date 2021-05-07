-- Script Date: 5/2/2021 9:44 PM  - ErikEJ.SqlCeScripting version 3.5.2.87
CREATE TABLE [Verbsets] (
  [vsid] INTEGER NOT NULL
, [travelID] INTEGER NOT NULL
, [numVerbs] NUMERIC NOT NULL
, [numCond] NUMERIC NULL
, CONSTRAINT [PK_Verbsets] PRIMARY KEY ([vsid])
);
