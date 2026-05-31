#ifndef GUARD_FIELD_MUGSHOTS_H
#define GUARD_FIELD_MUGSHOTS_H

void _CreateFieldMugshot(u32 id, u32 emote);
void RemoveFieldMugshot(void);
u8 GetFieldMugshotSpriteId(void);
u8 IsFieldMugshotActive(void);
void SetFieldMugshotSpriteId(u32 value);
void SetFieldMugshotObjectEventSource(u8 objectEventId);
void ClearFieldMugshotObjectEventSource(void);
void TryCreateFieldMugshotFromObjectEventSource(void);
void CreateAutoFieldMugshot(u32 id, u32 emote);
void ShowFieldMugshot(void);
u16 GetFieldMugshotId(void);
u16 GetFieldMugshotIdFromObjectEventSource(void);

#endif // GUARD_FIELD_MUGSHOTS_H
