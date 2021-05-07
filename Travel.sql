-- Script Date: 5/2/2021 10:34 PM  - ErikEJ.SqlCeScripting version 3.5.2.87
CREATE TABLE [Travel] (
  [tid] INTEGER NOT NULL
, [LocationID] INTEGER NOT NULL
, [numVerbs] INTEGER NOT NULL
, [action] TEXT NOT NULL
, [destination] TEXT NOT NULL
, CONSTRAINT [PK_Travel] PRIMARY KEY ([tid])
);
