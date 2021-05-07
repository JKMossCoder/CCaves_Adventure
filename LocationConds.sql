-- Script Date: 5/3/2021 7:56 PM  - ErikEJ.SqlCeScripting version 3.5.2.87
CREATE TABLE [LocConditions] (
  [Id] INTEGER NOT NULL
, [LocationId] INTEGER NOT NULL
, [conditionId] INTEGER NOT NULL
, CONSTRAINT [PK_LocConditions] PRIMARY KEY ([Id])
);
