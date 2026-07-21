int	survives(int days_from_epoch, int tz_offset_hours)
{
	long localtime;

	localtime = (long)days_from_epoch * 86400 + (long)tz_offset_hours * 3600;
	return (localtime >= 0);
}
