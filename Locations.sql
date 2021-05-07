-- Script Date: 5/2/2021 10:39 PM  - ErikEJ.SqlCeScripting version 3.5.2.87
CREATE TABLE [Locations] (
  [locID] INTEGER NOT NULL
, [locName] TEXT NOT NULL
, [numTSets] INTEGER NULL
, [longDescription] TEXT NOT NULL
, [shortDescription] TEXT NULL
, CONSTRAINT [PK_Locations] PRIMARY KEY ([locID])
);
