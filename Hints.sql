-- Script Date: 5/3/2021 10:44 PM  - ErikEJ.SqlCeScripting version 3.5.2.87
DROP TABLE [Hints];
CREATE TABLE [Hints] (
  [HintId] INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL
, [Nane] text NOT NULL
, [HintNumber] bigint NOT NULL
, [Turns] bigint NOT NULL
, [Penelty] bigint NOT NULL
, [Question] text NOT NULL
, [Hint] text NOT NULL
);
