-- Script Date: 5/4/2021 7:17 AM  - ErikEJ.SqlCeScripting version 3.5.2.87
CREATE TABLE [ObjectStates] (
  [OSID] INTEGER NOT NULL
, [State] TEXT NOT NULL
, [Description] TEXT NULL
, [Changes] TEXT NULL
, [Sounds] TEXT NULL
, [Texts] TEXT NULL
, CONSTRAINT [PK_ObjectStates] PRIMARY KEY ([OSID])
);
